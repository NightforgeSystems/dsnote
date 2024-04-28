/* Copyright (C) 2021-2024 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dsnote.Settings 1.0

Page {
    id: root

    allowedOrientations: Orientation.All

    SilicaFlickable {
        id: flick
        anchors.fill: parent
        contentHeight: column.height

        Column {
            id: column

            width: root.width
            spacing: Theme.paddingMedium

            PageHeader {
                title: qsTr("Settings")
            }

            ExpandingSectionGroup {
                ExpandingSection {
                    title: qsTr("User Interface")

                    content.sourceComponent: Column {
                        TextSwitch {
                            checked: _settings.keep_last_note
                            automaticCheck: false
                            text: qsTr("Remember the last note")
                            description: qsTr("The note will be saved automatically, so when you restart the app, your last note will always be available.")
                            onClicked: {
                                _settings.keep_last_note = !_settings.keep_last_note
                            }
                        }

                        ComboBox {
                            label: qsTr("File import action")
                            currentIndex: {
                                if (_settings.file_import_action === Settings.FileImportActionAsk) return 0
                                if (_settings.file_import_action === Settings.FileImportActionAppend) return 1
                                if (_settings.file_import_action === Settings.FileImportActionReplace) return 2
                                return 0
                            }
                            menu: ContextMenu {
                                MenuItem { text: qsTr("Ask whether to add or replace") }
                                MenuItem { text: qsTr("Add to an existing note") }
                                MenuItem { text: qsTr("Replace an existing note") }
                            }
                            onCurrentIndexChanged: {
                                if (currentIndex === 1) {
                                    _settings.file_import_action = Settings.FileImportActionAppend
                                } else if (currentIndex === 2) {
                                    _settings.file_import_action = Settings.FileImportActionReplace
                                } else {
                                    _settings.file_import_action = Settings.FileImportActionAsk
                                }
                            }
                            description: qsTr("The action when importing a note from a file. You can add imported text to an existing note or replace an existing note.")
                        }

                        ComboBox {
                            label: qsTr("Text appending style")
                            currentIndex: {
                                if (_settings.insert_mode === Settings.InsertInLine) return 0
                                if (_settings.insert_mode === Settings.InsertNewLine) return 1
                                if (_settings.insert_mode === Settings.InsertAfterEmptyLine) return 2
                                return 0
                            }
                            menu: ContextMenu {
                                MenuItem { text: qsTr("In line") }
                                MenuItem { text: qsTr("After line break") }
                                MenuItem { text: qsTr("After empty line") }
                            }
                            onCurrentIndexChanged: {
                                if (currentIndex === 0) {
                                    _settings.insert_mode = Settings.InsertInLine
                                } else if (currentIndex === 1) {
                                    _settings.insert_mode = Settings.InsertNewLine
                                } else if (currentIndex === 2) {
                                    _settings.insert_mode = Settings.InsertAfterEmptyLine
                                } else {
                                    _settings.insert_mode = Settings.InsertInLine
                                }
                            }
                            description: qsTr("Text is appended to the note in the same line or after line break.")
                        }
                    }
                }

                ExpandingSection {
                    title: qsTr("Speech to Text")

                    content.sourceComponent: Column {
                        ComboBox {
                            label: qsTr("Listening mode")
                            currentIndex: {
                                if (_settings.speech_mode === Settings.SpeechSingleSentence) return 0
                                if (_settings.speech_mode === Settings.SpeechAutomatic) return 2
                                return 1
                            }
                            menu: ContextMenu {
                                MenuItem { text: qsTr("One sentence") }
                                MenuItem { text: qsTr("Press and hold") }
                                MenuItem { text: qsTr("Always on") }
                            }
                            onCurrentIndexChanged: {
                                if (currentIndex === 0) {
                                    _settings.speech_mode = Settings.SpeechSingleSentence
                                } else if (currentIndex === 2) {
                                    _settings.speech_mode = Settings.SpeechAutomatic
                                } else {
                                    _settings.speech_mode = Settings.SpeechManual
                                }
                            }
                            description: "<i>" + qsTr("One sentence") + "</i>" + " — " + qsTr("Clicking on the %1 button starts listening, which ends when the first sentence is recognized.")
                                            .arg("<i>" + qsTr("Listen") + "</i>") + "<br/>" +
                                         "<i>" + qsTr("Press and hold") + "</i>" + " — " + qsTr("Pressing and holding the %1 button enables listening. When you stop holding, listening will turn off.")
                                            .arg("<i>" + qsTr("Listen") + "</i>") + "<br/>" +
                                         "<i>" + qsTr("Always on") + "</i>" + " — " + qsTr("After clicking on the %1 button, listening is always turn on.")
                                            .arg("<i>" + qsTr("Listen") + "</i>")
                        }

                        SectionHeader {
                            text: qsTr("Subtitles")
                        }

                        Slider {
                            id: subSegDurSlider

                            label: qsTr("Minimum segment duration")
                            opacity: enabled ? 1.0 : Theme.opacityLow
                            width: parent.width
                            minimumValue: 1
                            maximumValue: 60
                            stepSize: 1
                            value: _settings.sub_min_segment_dur
                            valueText: "" + value + " s"
                            onValueChanged: {
                                _settings.sub_min_segment_dur = subSegDurSlider.value;
                            }

                            Connections {
                                target: _settings
                                onSub_min_segment_durChanged: {
                                    subSegDurSlider.value = _settings.sub_min_segment_dur
                                }
                            }
                        }

                        PaddedLabel {
                            font.pixelSize: Theme.fontSizeExtraSmall
                            color: Theme.secondaryColor
                            text: qsTr("Set the minimum duration (in seconds) of the subtitle segment.") + " " +
                                  qsTr("This option only works with %1 and %2 models.").arg("<i>DeepSpeech/Coqui</i>").arg("<i>Vosk</i>")
                        }

                        TextSwitch {
                            checked: _settings.sub_break_lines
                            automaticCheck: false
                            text: qsTr("Break text lines")
                            onClicked: {
                                _settings.sub_break_lines = !_settings.sub_break_lines
                            }
                        }

                        Slider {
                            id: subMinLineSlider

                            visible: _settings.sub_break_lines
                            label: qsTr("Minimum line length")
                            opacity: enabled ? 1.0 : Theme.opacityLow
                            width: parent.width
                            minimumValue: 1
                            maximumValue: 1000
                            stepSize: 1
                            value: _settings.sub_min_line_length
                            valueText: value
                            onValueChanged: {
                                _settings.sub_min_line_length = subMinLineSlider.value;
                                if (_settings.sub_max_line_length < subMinLineSlider.value)
                                    _settings.sub_max_line_length = subMinLineSlider.value
                            }

                            Connections {
                                target: _settings
                                onSub_min_line_lengthChanged: {
                                    subMinLineSlider.value = _settings.sub_min_line_length
                                }
                            }
                        }

                        Slider {
                            id: subMaxLineSlider

                            visible: _settings.sub_break_lines
                            label: qsTr("Maximum line length")
                            opacity: enabled ? 1.0 : Theme.opacityLow
                            width: parent.width
                            minimumValue: 1
                            maximumValue: 1000
                            stepSize: 1
                            value: _settings.sub_max_line_length
                            valueText: value
                            onValueChanged: {
                                _settings.sub_max_line_length = subMaxLineSlider.value;
                                if (_settings.sub_min_line_length > subMaxLineSlider.value)
                                    _settings.sub_min_line_length = subMaxLineSlider.value;
                            }

                            Connections {
                                target: _settings
                                onSub_max_line_lengthChanged: {
                                    subMaxLineSlider.value = _settings.sub_max_line_length
                                }
                            }
                        }
                    }
                }

                ExpandingSection {
                    title: qsTr("Text to Speech")

                    content.sourceComponent: Column {
                        Slider {
                            id: speechSpeedSlider

                            opacity: enabled ? 1.0 : Theme.opacityLow
                            width: parent.width
                            minimumValue: 1
                            maximumValue: 20
                            stepSize: 1
                            handleVisible: true
                            label: qsTr("Speech speed")
                            value: _settings.speech_speed
                            valueText: "x " + (value / 10).toFixed(1)
                            onValueChanged: _settings.speech_speed = value

                            Connections {
                                target: _settings
                                onSpeech_speedChanged: {
                                    speechSpeedSlider.value = _settings.speech_speed
                                }
                            }
                        }

                        TextSwitch {
                            checked: _settings.diacritizer_enabled
                            automaticCheck: false
                            text: qsTr("Restore diacritics before speech synthesis")
                            description: qsTr("This works only for Arabic language.")
                            onClicked: {
                                _settings.diacritizer_enabled = !_settings.diacritizer_enabled
                            }
                        }

                        TextSwitch {
                            checked: _settings.tts_split_into_sentences
                            automaticCheck: false
                            text: qsTr("Split text into sentences")
                            description: qsTr("The text will be divided into sentences and speech synthesis for each sentence will be performed in parallel.") + " " +
                                         qsTr("This speeds up reading, but in some models the naturalness of speech may be reduced.")
                            onClicked: {
                                _settings.tts_split_into_sentences = !_settings.tts_split_into_sentences
                            }
                        }

                        TextSwitch {
                            checked: _settings.tts_use_engine_speed_control
                            automaticCheck: false
                            text: qsTr("Use engine speed control")
                            description: qsTr("If the TTS engine supports speed control, it will be used.") + " " +
                                         qsTr("When this option is disabled, speed manipulation takes place during audio post-processing.") + " " +
                                         qsTr("The actual speed after audio post-processing is much more predictable, but the naturalness of speech may be reduced.")
                            onClicked: {
                                _settings.tts_use_engine_speed_control = !_settings.tts_use_engine_speed_control
                            }
                        }

                        SectionHeader {
                            text: qsTr("Subtitles")
                        }

                        ComboBox {
                            label: qsTr("Sync speech with timestamps")
                            currentIndex: {
                                if (_settings.tts_subtitles_sync === Settings.TtsSubtitleSyncOff) return 0
                                if (_settings.tts_subtitles_sync === Settings.TtsSubtitleSyncOnDontFit) return 1
                                if (_settings.tts_subtitles_sync === Settings.TtsSubtitleSyncOnFitOnlyIfLonger) return 2
                                if (_settings.tts_subtitles_sync === Settings.TtsSubtitleSyncOnAlwaysFit) return 3
                                return 1
                            }
                            menu: ContextMenu {
                                MenuItem { text: qsTr("Don't sync") }
                                MenuItem { text: qsTr("Sync but don't adjust speed") }
                                MenuItem { text: qsTr("Sync and increase speed to fit") }
                                MenuItem { text: qsTr("Sync and increase or decrease speed to fit") }
                            }
                            onCurrentIndexChanged: {
                                if (currentIndex === 1) {
                                    _settings.tts_subtitles_sync = Settings.TtsSubtitleSyncOnDontFit
                                } else if (currentIndex === 2) {
                                    _settings.tts_subtitles_sync = Settings.TtsSubtitleSyncOnFitOnlyIfLonger
                                } else if (currentIndex === 3) {
                                    _settings.tts_subtitles_sync = Settings.TtsSubtitleSyncOnAlwaysFit
                                } else {
                                    _settings.tts_subtitles_sync = Settings.TtsSubtitleSyncOff
                                }
                            }
                            description: "<i>" + qsTr("Don't sync") + "</i>" + " — " + qsTr("Subtitle timestamps are ignored when reading or exporting to a file.") + "<br/> " +
                                         "<i>" + qsTr("Sync but don't adjust speed") + "</i>" + " — " + qsTr("Speech is synchronized according to timestamps.") + "<br/> " +
                                         "<i>" + qsTr("Sync and only increase speed to fit") + "</i>" + " — " + qsTr("Speech is synchronized according to timestamps. The speed is adjusted automatically so that the duration of the speech is never longer than the duration of the subtitle segment.")  + "<br/> " +
                                         "<i>" + qsTr("Sync and increase or decrease speed to fit") + "</i>" + " — " + qsTr("Speech is synchronized according to timestamps. The speed is adjusted automatically so that the duration of the speech is exactly the same as the duration of the subtitle segment.")
                        }

                        PaddedLabel {
                            visible: _settings.tts_subtitles_sync === Settings.TtsSubtitleSyncOnFitOnlyIfLonger ||
                                     _settings.tts_subtitles_sync === Settings.TtsSubtitleSyncOnAlwaysFit
                            font.pixelSize: Theme.fontSizeSmall
                            color: Theme.secondaryColor
                            text: qsTr("When SRT Subtitles text format is set, changing the speech speed is disabled because the speed will be adjusted automatically.")
                        }
                    }
                }

                ExpandingSection {
                    title: qsTr("Other")

                    content.sourceComponent: Column {
                        TextSwitch {
                            checked: _settings.cache_policy === Settings.CacheRemove
                            automaticCheck: false
                            text: qsTr("Clear cache on close")
                            description: qsTr("When closing, delete all cached audio files.")
                            onClicked: {
                                _settings.cache_policy =
                                        _settings.cache_policy === Settings.CacheRemove ?
                                            Settings.CacheNoRemove : Settings.CacheRemove
                            }
                        }

                        ItemBox {
                            title: qsTr("Location of language files")
                            value: _settings.models_dir_name
                            description: qsTr("Directory where language files are downloaded to and stored.")

                            menu: ContextMenu {
                                MenuItem {
                                    text: qsTr("Change")
                                    onClicked: {
                                        var obj = pageStack.push(Qt.resolvedUrl("DirPage.qml"), {path: _settings.models_dir});
                                        obj.accepted.connect(function() {
                                            _settings.models_dir = obj.selectedPath
                                        })
                                    }
                                }
                                MenuItem {
                                    text: qsTr("Set default")
                                    onClicked: {
                                        _settings.models_dir = ""
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    RemorsePopup {
        id: remorse
    }

    VerticalScrollDecorator {
        flickable: flick
    }
}
