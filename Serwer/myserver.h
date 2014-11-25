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

signals:

public slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // MYSERVER_H
