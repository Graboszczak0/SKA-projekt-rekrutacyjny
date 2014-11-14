#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

signals:

public slots:
    void newConnection();
    void readyRead();
    void Send(QByteArray message);

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // MYSERVER_H
