#include "myserver.h"

MyServer* serwer;

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    server = new QTcpServer(this);
    socket = new QTcpSocket(this);

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    /*
     * Podstawowe ustawienia serwera.
     */
    server->listen(QHostAddress::Any,1234);
}

void MyServer::newConnection()
{
    /*
     * Połączenie serwera z klientem.
     */
    socket = server->nextPendingConnection();
    socket->write("Connected\r\n");
    qDebug()<<"Connected";
    socket->flush();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void MyServer::readyRead()
{
   // qDebug()<<"\n\n\nreading network socket\n\n\n";
    QString In = socket->readAll();
    QString Com;
    /*
     * Kontrola kompletności komunikatu, następnie jego interpretacja.
     */
    while(In[In.size()-1]!='\n')
    {
        socket->waitForReadyRead(0);
        QString TIn=socket->readAll();
        In=In+TIn;
    }
    for(int i=0, j=0; i<In.size(); i++, j++)
    {
        Com[j]=In[i];
        if(Com[j]=='\n')
        {
        MyCommands::CheckServer(Com);
        Com.clear();
        j=-1;
        }
    }
}

void MyServer::send(QByteArray S)
{
    /*
     * Odpowiedź serwera.
     */
    socket->write(S);
    socket->flush();
}
