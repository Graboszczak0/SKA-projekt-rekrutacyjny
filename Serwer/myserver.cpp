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
    connect(socket,SIGNAL(disconnected()),this,SLOT(checkConnection()));
}

void MyServer::readyRead()
{
   // socket->waitForReadyRead(1000);
    QString In = socket->readAll();
    QString Com;
    /*
     * Kontrola kompletności komunikatu, następnie jego interpretacja.
     */
    while(In[In.size()-1]!='\n')
    {
        //socket->waitForReadyRead(1000);
        QString TIn=socket->readAll();
        In=In+TIn;
    }
    for(int i=0, j=0; i<In.size(); i++)
    {
        Com[j]=In[i];
        if(Com[j]=='\n')
        {
            MyCommands::CheckServer(Com);
            Com.clear();
            j=0;
        }
        else
            j++;
    }
}

void MyServer::checkConnection()
{
    /*
     * Sprawdzanie stanu połączenia.
     */
    if(socket->state()==QAbstractSocket::UnconnectedState)
    {
        qDebug()<<"Notconnected";
        MyCommands::CheckServer("MP;0;0\n");
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
