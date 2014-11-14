#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    server = new QTcpServer(this);
    socket = new QTcpSocket(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    server->listen(QHostAddress::Any,1234);
}

void MyServer::newConnection()
{
    socket = server->nextPendingConnection();
    socket->write("Connected\r\n");
    qDebug()<<"Connected";
    socket->flush();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void MyServer::readyRead()
{
    socket->waitForReadyRead(1000);
    QByteArray In = socket->readAll();
    qDebug()<<In;
    //Reakcja na wejście
}

void MyServer::Send(QByteArray message)
{
    socket->write(message);
}
