#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QFuture>
#include <QtConcurrent>
#include <QLocalSocket>
#include <QList>
#include <QDebug>

#define SERVER_NAME "mpvguiserver"



class Server : public QObject
{
    Q_OBJECT
private:
    bool running;
    QFuture<void> loopThread;
    QLocalServer *myserver;
    QList<QLocalSocket*> *clients;


public:
    explicit Server(QObject *parent = 0);
    void listen();
    void clientLoop(void);

signals:
    void finished();

public slots:

private slots:
    void handleConnection();
    void readFromClient();
    void removeClient();

};

#endif // SERVER_H
