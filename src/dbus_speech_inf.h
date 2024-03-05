/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ../dbus/org.mkiol.Speech.xml -p dbus_speech_inf
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUS_SPEECH_INF_H
#define DBUS_SPEECH_INF_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.mkiol.Speech
 */
class OrgMkiolSpeechInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.mkiol.Speech"; }

public:
    OrgMkiolSpeechInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgMkiolSpeechInterface();

    Q_PROPERTY(int CurrentTask READ currentTask)
    inline int currentTask() const
    { return qvariant_cast< int >(property("CurrentTask")); }

    Q_PROPERTY(QString DefaultMntLang READ defaultMntLang WRITE setDefaultMntLang)
    inline QString defaultMntLang() const
    { return qvariant_cast< QString >(property("DefaultMntLang")); }
    inline void setDefaultMntLang(const QString &value)
    { setProperty("DefaultMntLang", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultMntOutLang READ defaultMntOutLang WRITE setDefaultMntOutLang)
    inline QString defaultMntOutLang() const
    { return qvariant_cast< QString >(property("DefaultMntOutLang")); }
    inline void setDefaultMntOutLang(const QString &value)
    { setProperty("DefaultMntOutLang", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultSttLang READ defaultSttLang WRITE setDefaultSttLang)
    inline QString defaultSttLang() const
    { return qvariant_cast< QString >(property("DefaultSttLang")); }
    inline void setDefaultSttLang(const QString &value)
    { setProperty("DefaultSttLang", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultSttModel READ defaultSttModel WRITE setDefaultSttModel)
    inline QString defaultSttModel() const
    { return qvariant_cast< QString >(property("DefaultSttModel")); }
    inline void setDefaultSttModel(const QString &value)
    { setProperty("DefaultSttModel", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultTtsLang READ defaultTtsLang WRITE setDefaultTtsLang)
    inline QString defaultTtsLang() const
    { return qvariant_cast< QString >(property("DefaultTtsLang")); }
    inline void setDefaultTtsLang(const QString &value)
    { setProperty("DefaultTtsLang", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultTtsModel READ defaultTtsModel WRITE setDefaultTtsModel)
    inline QString defaultTtsModel() const
    { return qvariant_cast< QString >(property("DefaultTtsModel")); }
    inline void setDefaultTtsModel(const QString &value)
    { setProperty("DefaultTtsModel", QVariant::fromValue(value)); }

    Q_PROPERTY(QVariantList MntLangList READ mntLangList)
    inline QVariantList mntLangList() const
    { return qvariant_cast< QVariantList >(property("MntLangList")); }

    Q_PROPERTY(QVariantMap MntLangs READ mntLangs)
    inline QVariantMap mntLangs() const
    { return qvariant_cast< QVariantMap >(property("MntLangs")); }

    Q_PROPERTY(int State READ state)
    inline int state() const
    { return qvariant_cast< int >(property("State")); }

    Q_PROPERTY(QVariantList SttLangList READ sttLangList)
    inline QVariantList sttLangList() const
    { return qvariant_cast< QVariantList >(property("SttLangList")); }

    Q_PROPERTY(QVariantMap SttLangs READ sttLangs)
    inline QVariantMap sttLangs() const
    { return qvariant_cast< QVariantMap >(property("SttLangs")); }

    Q_PROPERTY(QVariantMap SttModels READ sttModels)
    inline QVariantMap sttModels() const
    { return qvariant_cast< QVariantMap >(property("SttModels")); }

    Q_PROPERTY(QVariantList SttTtsLangList READ sttTtsLangList)
    inline QVariantList sttTtsLangList() const
    { return qvariant_cast< QVariantList >(property("SttTtsLangList")); }

    Q_PROPERTY(int TaskState READ taskState)
    inline int taskState() const
    { return qvariant_cast< int >(property("TaskState")); }

    Q_PROPERTY(QVariantMap Translations READ translations)
    inline QVariantMap translations() const
    { return qvariant_cast< QVariantMap >(property("Translations")); }

    Q_PROPERTY(QVariantList TtsLangList READ ttsLangList)
    inline QVariantList ttsLangList() const
    { return qvariant_cast< QVariantList >(property("TtsLangList")); }

    Q_PROPERTY(QVariantMap TtsLangs READ ttsLangs)
    inline QVariantMap ttsLangs() const
    { return qvariant_cast< QVariantMap >(property("TtsLangs")); }

    Q_PROPERTY(QVariantMap TtsModels READ ttsModels)
    inline QVariantMap ttsModels() const
    { return qvariant_cast< QVariantMap >(property("TtsModels")); }

    Q_PROPERTY(QVariantMap TttLangs READ tttLangs)
    inline QVariantMap tttLangs() const
    { return qvariant_cast< QVariantMap >(property("TttLangs")); }

    Q_PROPERTY(QVariantMap TttModels READ tttModels)
    inline QVariantMap tttModels() const
    { return qvariant_cast< QVariantMap >(property("TttModels")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<int> Cancel(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("Cancel"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> FeaturesAvailability()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("FeaturesAvailability"), argumentList);
    }

    inline QDBusPendingReply<int> KeepAliveService()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("KeepAliveService"), argumentList);
    }

    inline QDBusPendingReply<int> KeepAliveTask(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("KeepAliveTask"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> MntGetOutLangs(const QString &lang)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(lang);
        return asyncCallWithArgumentList(QStringLiteral("MntGetOutLangs"), argumentList);
    }

    inline QDBusPendingReply<int> MntTranslate(const QString &text, const QString &lang, const QString &out_lang)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(lang) << QVariant::fromValue(out_lang);
        return asyncCallWithArgumentList(QStringLiteral("MntTranslate"), argumentList);
    }

    inline QDBusPendingReply<int> MntTranslate2(const QString &text, const QString &lang, const QString &out_lang, const QVariantMap &options)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(lang) << QVariant::fromValue(out_lang) << QVariant::fromValue(options);
        return asyncCallWithArgumentList(QStringLiteral("MntTranslate2"), argumentList);
    }

    inline QDBusPendingReply<int> Reload()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reload"), argumentList);
    }

    inline QDBusPendingReply<double> SttGetFileTranscribeProgress(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("SttGetFileTranscribeProgress"), argumentList);
    }

    inline QDBusPendingReply<int> SttStartListen(int mode, const QString &lang, const QString &out_lang)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode) << QVariant::fromValue(lang) << QVariant::fromValue(out_lang);
        return asyncCallWithArgumentList(QStringLiteral("SttStartListen"), argumentList);
    }

    inline QDBusPendingReply<int> SttStartListen2(int mode, const QString &lang, const QString &out_lang, const QVariantMap &options)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode) << QVariant::fromValue(lang) << QVariant::fromValue(out_lang) << QVariant::fromValue(options);
        return asyncCallWithArgumentList(QStringLiteral("SttStartListen2"), argumentList);
    }

    inline QDBusPendingReply<int> SttStopListen(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("SttStopListen"), argumentList);
    }

    inline QDBusPendingReply<int> SttTranscribeFile(const QString &file, const QString &lang, const QString &out_lang, const QVariantMap &options)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(file) << QVariant::fromValue(lang) << QVariant::fromValue(out_lang) << QVariant::fromValue(options);
        return asyncCallWithArgumentList(QStringLiteral("SttTranscribeFile"), argumentList);
    }

    inline QDBusPendingReply<double> TtsGetSpeechToFileProgress(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("TtsGetSpeechToFileProgress"), argumentList);
    }

    inline QDBusPendingReply<int> TtsPauseSpeech(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("TtsPauseSpeech"), argumentList);
    }

    inline QDBusPendingReply<int> TtsPlaySpeech(const QString &text, const QString &lang)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(lang);
        return asyncCallWithArgumentList(QStringLiteral("TtsPlaySpeech"), argumentList);
    }

    inline QDBusPendingReply<int> TtsPlaySpeech2(const QString &text, const QString &lang, const QVariantMap &options)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(lang) << QVariant::fromValue(options);
        return asyncCallWithArgumentList(QStringLiteral("TtsPlaySpeech2"), argumentList);
    }

    inline QDBusPendingReply<int> TtsResumeSpeech(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("TtsResumeSpeech"), argumentList);
    }

    inline QDBusPendingReply<int> TtsSpeechToFile(const QString &text, const QString &lang, const QVariantMap &options)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(lang) << QVariant::fromValue(options);
        return asyncCallWithArgumentList(QStringLiteral("TtsSpeechToFile"), argumentList);
    }

    inline QDBusPendingReply<int> TtsStopSpeech(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("TtsStopSpeech"), argumentList);
    }

    inline QDBusPendingReply<int> TttRepairText(const QString &text, const QVariantMap &options)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(options);
        return asyncCallWithArgumentList(QStringLiteral("TttRepairText"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void CurrentTaskPropertyChanged(int task);
    void DefaultMntLangPropertyChanged(const QString &lang);
    void DefaultMntOutLangPropertyChanged(const QString &lang);
    void DefaultSttLangPropertyChanged(const QString &lang);
    void DefaultSttModelPropertyChanged(const QString &model);
    void DefaultTtsLangPropertyChanged(const QString &lang);
    void DefaultTtsModelPropertyChanged(const QString &model);
    void ErrorOccured(int code);
    void FeaturesAvailabilityUpdated();
    void MntLangListChanged(const QVariantList &langs);
    void MntLangsPropertyChanged(const QVariantMap &langs);
    void MntTranslateFinished(const QString &in_text, const QString &in_lang, const QString &out_text, const QString &out_lang, int task);
    void MntTranslateProgress(double progress, int task);
    void StatePropertyChanged(int state);
    void SttFileTranscribeFinished(int task);
    void SttFileTranscribeProgress(double progress, int task);
    void SttIntermediateTextDecoded(const QString &text, const QString &lang, int task);
    void SttLangListChanged(const QVariantList &langs);
    void SttLangsPropertyChanged(const QVariantMap &langs);
    void SttModelsPropertyChanged(const QVariantMap &models);
    void SttTextDecoded(const QString &text, const QString &lang, int task);
    void SttTtsLangListChanged(const QVariantList &langs);
    void TaskStatePropertyChanged(int taskState);
    void TtsLangListChanged(const QVariantList &langs);
    void TtsLangsPropertyChanged(const QVariantMap &langs);
    void TtsModelsPropertyChanged(const QVariantMap &models);
    void TtsPartialSpeechPlaying(const QString &text, int task);
    void TtsPlaySpeechFinished(int task);
    void TtsSpeechToFileFinished(const QStringList &files, int task);
    void TtsSpeechToFileProgress(double progress, int task);
    void TttLangsPropertyChanged(const QVariantMap &langs);
    void TttModelsPropertyChanged(const QVariantMap &models);
    void TttRepairTextFinished(const QString &text, int task);
};

namespace org {
  namespace mkiol {
    typedef ::OrgMkiolSpeechInterface Speech;
  }
}
#endif
