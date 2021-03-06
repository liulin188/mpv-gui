//Author : CONGILIO Luigi    CONSTANS Victor

#ifndef GUISERVER_H
#define GUISERVER_H

#include <QLocalSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <stdexcept>
#include <iostream>

using namespace std;

enum {
    CONFIG,
    PAUSE,
    UNPAUSE,
    LOAD,
    PIECELOAD,
    RADIOLOAD,
    LISTLOAD,
    STOP,
    PERCENT_POS,
    TIME_POS,
    DURATION,
    META,
    VOLUME,
    STEP_FOR,
    STEP_BACK,
    NEXT,
    PREV
};


class GuiServer : public QLocalSocket
{
    Q_OBJECT
public:
    explicit GuiServer(QObject *parent);
    ~GuiServer();

signals:


public slots:
    void send_command(int type,const QString data);
    void send_command(int type);

    void pause();
    void unpause();
    void loadPiece(const QString file);
    void loadRadio(const QString file);
    void loadPlaylist(const QString playlist, int nb);
    void percent_pos(double pos);
    void volume(int value);
    void stop();
    void step_forward();
    void step_backward();
    void next();
    void prev();
    QString jsonToString(QJsonObject *o);


};

#endif // GUISERVER_H
