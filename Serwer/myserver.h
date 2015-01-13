#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include "mycommands.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void send(QByteArray S);

signals:

public slots:
    void newConnection();
    void readyRead();
    void checkConnection();

private:
    QTcpServer *server;
    QTcpSocket *socket;


};

extern MyServer* serwer;

#endif // MYSERVER_H
