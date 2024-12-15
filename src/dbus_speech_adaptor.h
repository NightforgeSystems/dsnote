/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ../dbus/org.mkiol.Speech.xml -a dbus_speech_adaptor
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef DBUS_SPEECH_ADAPTOR_H
#define DBUS_SPEECH_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface org.mkiol.Speech
 */
class SpeechAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.mkiol.Speech")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.mkiol.Speech\">\n"
"    <property access=\"read\" type=\"i\" name=\"State\"/>\n"
"    <signal name=\"StatePropertyChanged\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"state\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"i\" name=\"TaskState\"/>\n"
"    <signal name=\"TaskStatePropertyChanged\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"taskState\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"s\" name=\"DefaultSttLang\"/>\n"
"    <signal name=\"DefaultSttLangPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"lang\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"s\" name=\"DefaultTtsLang\"/>\n"
"    <signal name=\"DefaultTtsLangPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"lang\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"s\" name=\"DefaultSttModel\"/>\n"
"    <signal name=\"DefaultSttModelPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"model\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"s\" name=\"DefaultTtsModel\"/>\n"
"    <signal name=\"DefaultTtsModelPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"model\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"s\" name=\"DefaultMntLang\"/>\n"
"    <signal name=\"DefaultMntLangPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"lang\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"s\" name=\"DefaultMntOutLang\"/>\n"
"    <signal name=\"DefaultMntOutLangPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"lang\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"SttLangs\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"SttLangsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"av\" name=\"SttLangList\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"SttLangListChanged\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"av\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"TtsLangs\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"TtsLangsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"MntLangs\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"MntLangsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"av\" name=\"TtsLangList\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"TtsLangListChanged\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"av\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"av\" name=\"SttTtsLangList\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"SttTtsLangListChanged\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"av\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"av\" name=\"MntLangList\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"MntLangListChanged\">\n"
"      <annotation value=\"QVariantList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"av\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"SttModels\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"SttModelsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"models\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"TtsModels\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"TtsModelsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"models\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"i\" name=\"CurrentTask\"/>\n"
"    <signal name=\"CurrentTaskPropertyChanged\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"SttIntermediateTextDecoded\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"SttTextDecoded\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"SttFileTranscribeFinished\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"TtsPlaySpeechFinished\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"TtsSpeechToFileFinished\">\n"
"      <annotation value=\"QStringList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"as\" name=\"files\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"TtsPartialSpeechPlaying\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"TtsSpeechToFileProgress\">\n"
"      <arg direction=\"out\" type=\"d\" name=\"progress\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"SttFileTranscribeProgress\">\n"
"      <arg direction=\"out\" type=\"d\" name=\"progress\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"MntTranslateProgress\">\n"
"      <arg direction=\"out\" type=\"d\" name=\"progress\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <signal name=\"MntTranslateFinished\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"in_text\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"in_lang\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"out_text\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"out_lang\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"    <method name=\"SttGetFileTranscribeProgress\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"d\" name=\"progress\"/>\n"
"    </method>\n"
"    <method name=\"TtsGetSpeechToFileProgress\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"d\" name=\"progress\"/>\n"
"    </method>\n"
"    <method name=\"MntTranslate\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"out_lang\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"MntTranslate2\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In3\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"out_lang\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"options\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"MntGetOutLangs\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"out_langs\"/>\n"
"    </method>\n"
"    <signal name=\"ErrorOccured\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"code\"/>\n"
"    </signal>\n"
"    <method name=\"SttStartListen\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"mode\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"out_lang\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"SttStartListen2\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In3\"/>\n"
"      <arg direction=\"in\" type=\"i\" name=\"mode\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"out_lang\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"options\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"SttStopListen\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"SttTranscribeFile\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In3\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"file\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"out_lang\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"options\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"TtsPlaySpeech\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"TtsPlaySpeech2\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"options\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"TtsStopSpeech\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"TtsSpeechToFile\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"lang\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"options\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <method name=\"TtsPauseSpeech\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"TtsResumeSpeech\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"Cancel\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"FeaturesAvailability\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"features\"/>\n"
"    </method>\n"
"    <signal name=\"FeaturesAvailabilityUpdated\"/>\n"
"    <method name=\"Reload\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"KeepAliveTask\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"task\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"timer\"/>\n"
"    </method>\n"
"    <method name=\"KeepAliveService\">\n"
"      <arg direction=\"out\" type=\"i\" name=\"timer\"/>\n"
"    </method>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"Translations\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"TttLangs\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"TttLangsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"langs\"/>\n"
"    </signal>\n"
"    <property access=\"read\" type=\"a{sv}\" name=\"TttModels\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
"    </property>\n"
"    <signal name=\"TttModelsPropertyChanged\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"      <arg direction=\"out\" type=\"a{sv}\" name=\"models\"/>\n"
"    </signal>\n"
"    <method name=\"TttRepairText\">\n"
"      <annotation value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"options\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </method>\n"
"    <signal name=\"TttRepairTextFinished\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"text\"/>\n"
"      <arg direction=\"out\" type=\"i\" name=\"task\"/>\n"
"    </signal>\n"
"  </interface>\n"
        "")
public:
    SpeechAdaptor(QObject *parent);
    virtual ~SpeechAdaptor();

public: // PROPERTIES
    Q_PROPERTY(int CurrentTask READ currentTask)
    int currentTask() const;

    Q_PROPERTY(QString DefaultMntLang READ defaultMntLang WRITE setDefaultMntLang)
    QString defaultMntLang() const;
    void setDefaultMntLang(const QString &value);

    Q_PROPERTY(QString DefaultMntOutLang READ defaultMntOutLang WRITE setDefaultMntOutLang)
    QString defaultMntOutLang() const;
    void setDefaultMntOutLang(const QString &value);

    Q_PROPERTY(QString DefaultSttLang READ defaultSttLang WRITE setDefaultSttLang)
    QString defaultSttLang() const;
    void setDefaultSttLang(const QString &value);

    Q_PROPERTY(QString DefaultSttModel READ defaultSttModel WRITE setDefaultSttModel)
    QString defaultSttModel() const;
    void setDefaultSttModel(const QString &value);

    Q_PROPERTY(QString DefaultTtsLang READ defaultTtsLang WRITE setDefaultTtsLang)
    QString defaultTtsLang() const;
    void setDefaultTtsLang(const QString &value);

    Q_PROPERTY(QString DefaultTtsModel READ defaultTtsModel WRITE setDefaultTtsModel)
    QString defaultTtsModel() const;
    void setDefaultTtsModel(const QString &value);

    Q_PROPERTY(QVariantList MntLangList READ mntLangList)
    QVariantList mntLangList() const;

    Q_PROPERTY(QVariantMap MntLangs READ mntLangs)
    QVariantMap mntLangs() const;

    Q_PROPERTY(int State READ state)
    int state() const;

    Q_PROPERTY(QVariantList SttLangList READ sttLangList)
    QVariantList sttLangList() const;

    Q_PROPERTY(QVariantMap SttLangs READ sttLangs)
    QVariantMap sttLangs() const;

    Q_PROPERTY(QVariantMap SttModels READ sttModels)
    QVariantMap sttModels() const;

    Q_PROPERTY(QVariantList SttTtsLangList READ sttTtsLangList)
    QVariantList sttTtsLangList() const;

    Q_PROPERTY(int TaskState READ taskState)
    int taskState() const;

    Q_PROPERTY(QVariantMap Translations READ translations)
    QVariantMap translations() const;

    Q_PROPERTY(QVariantList TtsLangList READ ttsLangList)
    QVariantList ttsLangList() const;

    Q_PROPERTY(QVariantMap TtsLangs READ ttsLangs)
    QVariantMap ttsLangs() const;

    Q_PROPERTY(QVariantMap TtsModels READ ttsModels)
    QVariantMap ttsModels() const;

    Q_PROPERTY(QVariantMap TttLangs READ tttLangs)
    QVariantMap tttLangs() const;

    Q_PROPERTY(QVariantMap TttModels READ tttModels)
    QVariantMap tttModels() const;

public Q_SLOTS: // METHODS
    int Cancel(int task);
    QVariantMap FeaturesAvailability();
    int KeepAliveService();
    int KeepAliveTask(int task);
    QVariantMap MntGetOutLangs(const QString &lang);
    int MntTranslate(const QString &text, const QString &lang, const QString &out_lang);
    int MntTranslate2(const QString &text, const QString &lang, const QString &out_lang, const QVariantMap &options);
    int Reload();
    double SttGetFileTranscribeProgress(int task);
    int SttStartListen(int mode, const QString &lang, const QString &out_lang);
    int SttStartListen2(int mode, const QString &lang, const QString &out_lang, const QVariantMap &options);
    int SttStopListen(int task);
    int SttTranscribeFile(const QString &file, const QString &lang, const QString &out_lang, const QVariantMap &options);
    double TtsGetSpeechToFileProgress(int task);
    int TtsPauseSpeech(int task);
    int TtsPlaySpeech(const QString &text, const QString &lang);
    int TtsPlaySpeech2(const QString &text, const QString &lang, const QVariantMap &options);
    int TtsResumeSpeech(int task);
    int TtsSpeechToFile(const QString &text, const QString &lang, const QVariantMap &options);
    int TtsStopSpeech(int task);
    int TttRepairText(const QString &text, const QVariantMap &options);
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

#endif
