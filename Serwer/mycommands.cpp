#include "mycommands.h"
#include "myserial.h"
#include "myserver.h"

MyCommands::MyCommands(QObject *parent) :
    QObject(parent)
{
}

void MyCommands::CheckServer(QString S)
{
    if(S[0]=='M')
    Motors(S);
    if(S[0]=='B')
    {
        serial->send("b");
        qDebug()<<"Zapytanie Bateria";
    }
    if(S[0]=='C')
    {
        qDebug()<<"Nastawianie Zegara";

    }
}

void MyCommands::CheckSerial(char *S)
{
   QByteArray A;
   if(S[0]=='v')
   {
       A+='V';
       A+=';';
       A+=QByteArray::number((int)S[1]);
       A+=';';
       A+=QByteArray::number((int)S[2]);
       A+='\n';
       serwer->send(A);
       A.clear();
   }
   if(S[0]=='b')
   {
       A+='B';
       A+=';';
       A+=QByteArray::number((int)S[1]);
       A+='\n';
       serwer->send(A);
       A.clear();
   }
}

void MyCommands::Motors(QString S)
{
    QString L, R;
    int i=0;
    while(S[i+3]!=';')
       {
       L[i]=S[i+3];
       i++;
       }
    i=0;
    while(S[i+L.size()+4]!='\n')
       {
       R[i]=S[i+L.size()+4];
       i++;
       }
    int Li = L.toInt();
    int Ri = R.toInt();
    QByteArray A;
    if(S[1]=='V')   
    {
        qDebug()<< "Sterowanie predkoscia. Silnik lewy:"<< Li <<"Silnik prawy:"<< Ri;
        A+=(char)Li;
        serial->send("v");
        serial->send("l");
        serial->send(A);
        A.clear();
        A+=(char)Ri;
        serial->send("v");
        serial->send("r");
        serial->send(A);
        A.clear();

    }
    if(S[1]=='P')
    {
       qDebug()<< "Sterowanie PWM. Silnik lewy:"<< Li <<"Silnik prawy:"<< Ri;
       A+=(char)Li;
       serial->send("p");
       serial->send("l");
       serial->send(A);
       A.clear();
       A+=(char)Ri;
       serial->send("p");
       serial->send("r");
       serial->send(A);
       A.clear();
    }


}

