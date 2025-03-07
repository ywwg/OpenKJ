/*
 * Copyright (c) 2013-2019 Thomas Isaac Lightburn
 *
 *
 * This file is part of OpenKJ.
 *
 * OpenKJ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QHeaderView>
#include <QObject>
#include <QSettings>
#include <QSplitter>
#include <QTableView>
#include <QTreeView>
#include <QWidget>
#include <QMetaType>
#include <QDebug>
#include <QKeySequence>

struct SfxEntry
{
    SfxEntry();
    QString name;
    QString path;


}; Q_DECLARE_METATYPE(SfxEntry)

QDebug operator<<(QDebug dbg, const SfxEntry &entry);




typedef QList<SfxEntry> SfxEntryList;

Q_DECLARE_METATYPE(QList<SfxEntry>)

class Settings : public QObject
{
    Q_OBJECT

private:
    QSettings *settings;
    bool m_safeStartupMode{false};

public:
    bool lastStartupOk() const;
    void setStartupOk(const bool ok);
    QString lastRunVersion() const;
    void setLastRunVersion(const QString &version);
    bool safeStartupMode() const;
    void setSafeStartupMode(const bool safeMode);
    int historyDblClickAction() const;
    void setHistoryDblClickAction(const int index);
    int getSystemRamSize();
    int remainRtOffset();
    int remainBtmOffset();
    qint64 hash(const QString & str);
    bool progressiveSearchEnabled();
    QString storeDownloadDir();
    QString logDir();
    bool logShow();
    bool logEnabled();
    void setPassword(QString password);
    void clearPassword();
    bool chkPassword(QString password);
    bool passIsSet();
    void setCC(QString ccn, QString month, QString year, QString ccv, QString passwd);
    void setSaveCC(bool save);
    bool saveCC();
    void clearCC();
    void clearKNAccount();
    void setSaveKNAccount(bool save);
    bool saveKNAccount();
    bool testingEnabled();
    bool hardwareAccelEnabled();
    bool dbDoubleClickAddsSong();
    QString getCCN(const QString &password);
    QString getCCM(const QString &password);
    QString getCCY(const QString &password);
    QString getCCV(const QString &password);
    void setKaroakeDotNetUser(const QString &username, const QString &password);
    void setKaraokeDotNetPass(const QString &KDNPassword, const QString &password);
    QString karoakeDotNetUser(const QString &password);
    QString karoakeDotNetPass(const QString &password);
    enum BgMode { BG_MODE_IMAGE = 0, BG_MODE_SLIDESHOW };
    enum PreviewSize { Small, Medium, Large };
    explicit Settings(QObject *parent = 0);
    bool cdgWindowFullscreen();
    bool showCdgWindow();
    void setCdgWindowFullscreenMonitor(int monitor);
    int  cdgWindowFullScreenMonitor();
    bool controlBreakMusic();
    void setControlBreakMusic(bool control);
    bool fadeBreakMusic();
    void setFadeBreakMusic(bool fade);
    bool pauseBreakMusic();
    void setPauseBreakMusic(bool pause);
    bool fadeToStop();
    void setFadeToStop(bool fade);
    bool fadedPause();
    void setFadedPause(bool faded);
    bool silenceDetection();
    bool setSilenceDetection(bool detect);
    void saveWindowState(QWidget *window);
    void restoreWindowState(QWidget *window);
    void saveColumnWidths(QTreeView *treeView);
    void saveColumnWidths(QTableView *tableView);
    void restoreColumnWidths(QTreeView *treeView);
    void restoreColumnWidths(QTableView *tableView);
    void saveSplitterState(QSplitter *splitter);
    void restoreSplitterState(QSplitter *splitter);
    void setTickerFont(const QFont &font);
    void setApplicationFont(const QFont &font);
    QFont tickerFont();
    QFont applicationFont();
    int tickerHeight();
    void setTickerHeight(int height);
    int tickerSpeed();
    void setTickerSpeed(int speed);
    QColor tickerTextColor();
    void setTickerTextColor(QColor color);
    bool cdgRemainEnabled();
    QColor tickerBgColor();
    void setTickerBgColor(QColor color);
    bool tickerFullRotation();
    void setTickerFullRotation(bool full);
    int tickerShowNumSingers();
    void setTickerShowNumSingers(int limit);
    void setTickerEnabled(bool enable);
    bool tickerEnabled();
    QString tickerCustomString();
    void setTickerCustomString(const QString &value);
    bool tickerShowRotationInfo();
    bool requestServerEnabled();
    void setRequestServerEnabled(bool enable);
    QString requestServerUrl();
    void setRequestServerUrl(QString url);
    int requestServerVenue();
    void setRequestServerVenue(int venueId);
    QString requestServerApiKey();
    void setRequestServerApiKey(QString apiKey);
    bool requestServerIgnoreCertErrors();
    void setRequestServerIgnoreCertErrors(bool ignore);
    bool audioUseFader();
    bool audioUseFaderBm();
    void setAudioUseFader(bool fader);
    void setAudioUseFaderBm(bool fader);
    int audioVolume();
    void setAudioVolume(int volume);
    QString cdgDisplayBackgroundImage();
    void setCdgDisplayBackgroundImage(QString imageFile);
    BgMode bgMode();
    void setBgMode(BgMode mode);
    QString bgSlideShowDir();
    void setBgSlideShowDir(QString dir);
    bool audioDownmix();
    void setAudioDownmix(bool downmix);
    bool audioDownmixBm();
    void setAudioDownmixBm(bool downmix);
    bool audioDetectSilence();
    bool audioDetectSilenceBm();
    void setAudioDetectSilence(bool enabled);
    void setAudioDetectSilenceBm(bool enabled);
    QString audioOutputDevice();
    QString audioOutputDeviceBm();
    void setAudioOutputDevice(QString device);
    void setAudioOutputDeviceBm(QString device);
    int audioBackend();
    void setAudioBackend(int index);
    QString recordingContainer();
    void setRecordingContainer(QString container);
    QString recordingCodec();
    void setRecordingCodec(QString codec);
    QString recordingInput();
    void setRecordingInput(QString input);
    QString recordingOutputDir();
    void setRecordingOutputDir(QString path);
    bool recordingEnabled();
    void setRecordingEnabled(bool enabled);
    QString recordingRawExtension();
    void setRecordingRawExtension(QString extension);
    int cdgOffsetTop();
    int cdgOffsetBottom();
    int cdgOffsetLeft();
    int cdgOffsetRight();
    bool ignoreAposInSearch();
    int videoOffsetMs();
    bool bmShowFilenames();
    void bmSetShowFilenames(bool show);
    bool bmShowMetadata();
    void bmSetShowMetadata(bool show);
    int bmVolume();
    void bmSetVolume(int bmVolume);
    int bmPlaylistIndex();
    void bmSetPlaylistIndex(int index);
    int mplxMode();
    void setMplxMode(int mode);
    bool karaokeAutoAdvance();
    int karaokeAATimeout();
    void setKaraokeAATimeout(int secs);
    bool karaokeAAAlertEnabled();
    void setKaraokeAAAlertEnabled(bool enabled);
    QFont karaokeAAAlertFont();
    void setKaraokeAAAlertFont(QFont font);
    bool showQueueRemovalWarning();
    bool showSingerRemovalWarning();
    bool showSongInterruptionWarning();
    bool showSongPauseStopWarning();
    QColor alertTxtColor();
    QColor alertBgColor();
    bool bmAutoStart();
    void setBmAutoStart(bool enabled);
    int cdgDisplayOffset();
    QFont bookCreatorTitleFont();
    QFont bookCreatorArtistFont();
    QFont bookCreatorHeaderFont();
    QFont bookCreatorFooterFont();
    QString bookCreatorHeaderText();
    QString bookCreatorFooterText();
    bool bookCreatorPageNumbering();
    int bookCreatorSortCol();
    double bookCreatorMarginRt();
    double bookCreatorMarginLft();
    double bookCreatorMarginTop();
    double bookCreatorMarginBtm();
    int bookCreatorCols();
    int bookCreatorPageSize();
    bool eqKBypass();
    int getEqKLevel(int band);
    bool eqBBypass();
    int getEqBLevel(int band);
    int requestServerInterval();
    bool bmKCrossFade();
    bool requestRemoveOnRotAdd();
    bool requestDialogAutoShow();
    bool checkUpdates();
    int updatesBranch();
    int theme();
    const QPoint durationPosition();
    bool dbDirectoryWatchEnabled();
    SfxEntryList getSfxEntries();
    void addSfxEntry(SfxEntry entry);
    void setSfxEntries(SfxEntryList entries);
    int estimationSingerPad();
    void setEstimationSingerPad(int secs);
    int estimationEmptySongLength();
    void setEstimationEmptySongLength(int secs);
    bool estimationSkipEmptySingers();
    void setEstimationSkipEmptySingers(bool skip);
    bool rotationDisplayPosition();
    void setRotationDisplayPosition(bool show);
    int currentRotationPosition();
    bool dbSkipValidation();
    bool dbLazyLoadDurations();
    int systemId();
    QFont cdgRemainFont();
    QColor cdgRemainTextColor();
    QColor cdgRemainBgColor();
    bool rotationShowNextSong();
    void sync();
    bool previewEnabled();
    bool showMainWindowVideo();
    void setShowMainWindowVideo(const bool &show);
    bool showMainWindowSoundClips();
    void setShowMplxControls(const bool show);
    bool showMplxControls();
    void setShowMainWindowSoundClips(const bool &show);
    bool showMainWindowNowPlaying();
    void setShowMainWindowNowPlaying(const bool &show);
    int mainWindowVideoSize();
    void setMainWindowVideoSize(const PreviewSize &size);
    bool enforceAspectRatio();
    void setEnforceAspectRatio(const bool &enforce);
    QString auxTickerFile();
    QString uuid();
    uint slideShowInterval();
    int lastSingerAddPositionType();
    void saveShortcutKeySequence(const QString &name, const QKeySequence &sequence);
    QKeySequence loadShortcutKeySequence(const QString &name);
    bool cdgPrescalingEnabled();
    bool rotationAltSortOrder();
    bool treatAllSingersAsRegs();

signals:
    void treatAllSingersAsRegsChanged(const bool enabled);
    void slideShowIntervalChanged(const uint secs);
    void enforceAspectRatioChanged(const bool &enforce);
    void applicationFontChanged(QFont font);
    void tickerFontChanged();
    void tickerHeightChanged(int height);
    void tickerSpeedChanged();
    void tickerTextColorChanged();
    void tickerBgColorChanged();
    void tickerOutputModeChanged();
    void tickerEnableChanged();
    void tickerShowRotationInfoChanged(bool show);
    void audioBackendChanged(int index);
    void recordingSetupChanged();
    void cdgBgImageChanged();
    void cdgShowCdgWindowChanged(bool show);
    void cdgWindowFullscreenChanged(bool fullscreen);
    void cdgWindowFullscreenMonitorChanged(int monitor);
    void cdgOffsetsChanged();
    void bgModeChanged(BgMode mode);
    void bgSlideShowDirChanged(QString dir);
    void requestServerVenueChanged(int venueId);
    void tickerCustomStringChanged();
    void mplxModeChanged(int mode);
    void karaokeAAAlertFontChanged(QFont font);
    void karaokeAutoAdvanceChanged(bool enabled);
    void showQueueRemovalWarningChanged(bool enabled);
    void showSingerRemovalWarningChanged(bool enabled);
    void showSongInterruptionWarningChanged(bool enabled);
    void alertTxtColorChanged(QColor color);
    void alertBgColorChanged(QColor color);
    void showSongStopPauseWarningChanged(bool enabled);
    void eqKBypassChanged(bool bypass);
    void eqKLevelChanged(int band, int level);
    void eqBBypassChanged(bool bypass);
    void eqBLevelChanged(int band, int level);
    void requestServerIntervalChanged(int interval);
    void requestServerEnabledChanged(bool enabled);
    void rotationDisplayPositionChanged(bool show);
    void rotationDurationSettingsModified();
    void cdgRemainEnabledChanged(bool enabled);
    void cdgRemainFontChanged(QFont font);
    void cdgRemainTextColorChanged(QColor color);
    void cdgRemainBgColorChanged(QColor color);
    void rotationShowNextSongChanged(bool show);
    void remainOffsetChanged(int offsetR, int offsetB);
    void previewEnabledChanged(bool enabled);
    void durationPositionReset();
    void videoOffsetChanged(const int offsetMs);
    void lastSingerAddPositionTypeChanged(const int type);
    void shortcutsChanged();


public slots:
    void setTreatAllSingersAsRegs(const bool enabled);
    void setRotationAltSortOrder(bool enabled);
    void setCdgPrescalingEnabled(bool enabled);
    void setSlideShowInterval(int secs);
    void setHardwareAccelEnabled(const bool enabled);
    void setDbDoubleClickAddsSong(const bool enabled);
    void setDurationPosition(const QPoint pos);
    void resetDurationPosition();
    void setRemainRtOffset(int offset);
    void setRemainBtmOffset(int offset);
    void dbSetLazyLoadDurations(bool val);
    void dbSetSkipValidation(bool val);
    void setBmKCrossfade(bool enabled);
    void setShowCdgWindow(bool show);
    void setCdgWindowFullscreen(bool fullScreen);
    void setCdgOffsetTop(int pixels);
    void setCdgOffsetBottom(int pixels);
    void setCdgOffsetLeft(int pixels);
    void setCdgOffsetRight(int pixels);
    void setShowQueueRemovalWarning(bool show);
    void setShowSingerRemovalWarning(bool show);
    void setKaraokeAutoAdvance(bool enabled);
    void setShowSongInterruptionWarning(bool enabled);
    void setAlertBgColor(QColor color);
    void setAlertTxtColor(QColor color);
    void setIgnoreAposInSearch(bool ignore);
    void setShowSongPauseStopWarning(bool enabled);
    void setBookCreatorArtistFont(QFont font);
    void setBookCreatorTitleFont(QFont font);
    void setBookCreatorHeaderFont(QFont font);
    void setBookCreatorFooterFont(QFont font);
    void setBookCreatorHeaderText(QString text);
    void setBookCreatorFooterText(QString text);
    void setBookCreatorPageNumbering(bool show);
    void setBookCreatorSortCol(int col);
    void setBookCreatorMarginRt(double margin);
    void setBookCreatorMarginLft(double margin);
    void setBookCreatorMarginTop(double margin);
    void setBookCreatorMarginBtm(double margin);
    void setEqKBypass(bool bypass);
    void setEqKLevel(int band, int level);
    void setEqBBypass(bool bypass);
    void setEqBLevel(int band, int level);
    void setRequestServerInterval(int interval);
    void setTickerShowRotationInfo(bool show);
    void setRequestRemoveOnRotAdd(bool remove);
    void setRequestDialogAutoShow(bool enabled);
    void setCheckUpdates(bool enabled);
    void setUpdatesBranch(int index);
    void setTheme(int theme);
    void setBookCreatorCols(int cols);
    void setBookCreatorPageSize(int size);
    void setStoreDownloadDir(QString path);
    void setLogEnabled(bool enabled);
    void setLogVisible(bool visible);
    void setLogDir(QString path);
    void setCurrentRotationPosition(int position);
    void dbSetDirectoryWatchEnabled(bool val);
    void setSystemId(int id);
    void setCdgRemainEnabled(bool enabled);
    void setCdgRemainFont(QFont font);
    void setCdgRemainTextColor(QColor color);
    void setCdgRemainBgColor(QColor color);
    void setRotationShowNextSong(bool show);
    void setProgressiveSearchEnabled(bool enabled);
    void setPreviewEnabled(bool enabled);
    void setVideoOffsetMs(int offset);
    void setLastSingerAddPositionType(const int type);
};

#endif // KHSETTINGS_H
