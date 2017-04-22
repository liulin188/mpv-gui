#ifndef QMPVSOCKET_H
#define QMPVSOCKET_H

#include <QLocalSocket>

class QMpvSocket : public QLocalSocket
{
    Q_OBJECT
public:
    explicit QMpvSocket(QObject *parent = 0);
    QString quoted(const QString &s);

signals:

public slots:
    void send_command(const QString cmd[]);
    void observe_property(int id, const QString &prop);
    void set_property(const QString &prop, const QString &value);
    void set_property(const QString &prop, int value);
    void set_property(const QString &prop, bool value);
    void step_forward();
    void step_backward();
    void pause(bool value);
    void volume(int value);

};

#endif // QMPVSOCKET_H