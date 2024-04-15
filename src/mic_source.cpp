/* Copyright (C) 2021-2023 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "mic_source.h"

#include <QAudioFormat>
#include <QDebug>

#include "settings.h"

mic_source::mic_source(QObject* parent) : audio_source{parent} {
    qDebug() << "mic source created";
    init_audio();
    start();
}

mic_source::~mic_source() {
    qDebug() << "mic source dtor";
    m_audio_input->suspend();

    m_stopped = true;
}

bool mic_source::ok() const { return static_cast<bool>(m_audio_input); }

void mic_source::stop() {
    qDebug() << "mic source stop";
    m_audio_input->suspend();
    m_stopped = true;
}

void mic_source::slowdown() {
    // do notning
}

void mic_source::speedup() {
    // do notning
}

static QAudioFormat audio_format() {
    QAudioFormat format;
    format.setSampleRate(16000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec(QStringLiteral("audio/pcm"));
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    return format;
}

static bool has_audio_input(const QString& name) {
    auto ad_list = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    return std::find_if(ad_list.cbegin(), ad_list.cend(),
                        [&name](const auto& ad) {
                            return ad.deviceName() == name;
                        }) != ad_list.cend();
}

static QAudioDeviceInfo audio_input_info(const QString& name) {
    auto ad_list = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    return *std::find_if(
        ad_list.cbegin(), ad_list.cend(),
        [&name](const auto& ad) { return ad.deviceName() == name; });
}

QStringList mic_source::audio_inputs() {
    QStringList list;

    auto format = audio_format();

    auto ad_list = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    qDebug() << "supported audio input devices:";
    for (const auto& ad : ad_list) {
        if (ad.isFormatSupported(format)) {
            qDebug() << ad.deviceName();
            list.push_back(ad.deviceName());
        }
    }

    if (list.isEmpty()) qWarning() << "no supported audio input device";

    return list;
}

void mic_source::init_audio() {
    auto format = audio_format();

    auto input_name = settings::instance()->audio_input_device();
    if (input_name.isEmpty() || !has_audio_input(input_name)) {
        auto info = QAudioDeviceInfo::defaultInputDevice();
        if (info.isNull()) {
            qWarning() << "no audio input";
            throw std::runtime_error("no audio input");
        }

        input_name = info.deviceName();
    }

    auto input_info = audio_input_info(input_name);
    if (!input_info.isFormatSupported(format)) {
        qWarning() << "format not supported for audio input:"
                   << input_info.deviceName();
        throw std::runtime_error("audio format is not supported");
    }

    qDebug() << "using audio input:" << input_info.deviceName();
    m_audio_input = std::make_unique<QAudioInput>(input_info, format);

    connect(m_audio_input.get(), &QAudioInput::stateChanged, this,
            &mic_source::handle_state_changed);
}

void mic_source::start() {
    m_audio_device = m_audio_input->start();

    m_timer.setInterval(200);  // 200 ms
    connect(&m_timer, &QTimer::timeout, this, &mic_source::handle_read_timeout);
    m_timer.start();
}

void mic_source::handle_state_changed(QAudio::State new_state) {
    qDebug() << "audio state:" << new_state;

    if (new_state == QAudio::State::StoppedState ||
        new_state == QAudio::State::SuspendedState || m_stopped) {
        qDebug() << "audio ended";
        if (m_audio_input->error() == QAudio::NoError) m_eof = true;
    }
}

void mic_source::handle_read_timeout() {
    if (m_audio_input->error() != QAudio::NoError) {
        qWarning() << "audio input error:" << m_audio_input->error();
        m_timer.stop();
        emit error();
        return;
    }

    if (m_stopped && m_audio_input->state() != QAudio::State::SuspendedState)
        stop();

    /*bool bytes_available = !m_eof || m_audio_input->bytesReady() > 0;
    qDebug() << "mic read timeout: b_avai=" << bytes_available
             << "eof=" << m_eof << "ended=" << m_ended << "sof=" << m_sof
             << "b_ready=" << m_audio_input->bytesReady();*/

    if (m_ended) {
        emit ended();
        m_timer.stop();
        return;
    }

    emit audio_available();
}

void mic_source::clear() {
    qDebug() << "mic clear";

    char buff[std::numeric_limits<short>::max()];
    while (m_audio_device->read(buff, std::numeric_limits<short>::max()))
        continue;
}

audio_source::audio_data mic_source::read_audio(char* buf, size_t max_size) {
    audio_data data;
    data.data = buf;
    data.sof = m_sof;

    bool bytes_available = !m_eof || m_audio_input->bytesReady() > 0;

    /*qDebug() << "read_audio: b_avai=" << bytes_available << "eof=" << m_eof
             << "ended=" << m_ended << "sof=" << m_sof
             << "b_ready=" << m_audio_input->bytesReady();*/

    if (!bytes_available) {
        data.eof = m_eof;
        if (data.eof) m_ended = true;
        return data;
    }

    data.size = m_audio_device->read(buf, max_size);
    data.eof = m_eof && !bytes_available;

    m_sof = false;

    if (data.eof) m_ended = true;

    return data;
}
