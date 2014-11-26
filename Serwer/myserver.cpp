#include "myserver.h"

MyServer* serwer;

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
    QString In = socket->readAll();
    while(In[In.size()-1]!='\n')
    {
        socket->waitForReadyRead(1000);
        QString TIn=socket->readAll();
        In=In+TIn;
    }
    MyCommands::CheckServer(In);
}

void MyServer::send(QByteArray S)
{
    socket->write(S);
}
