#include "mycommands.h"
#include "myserial.h"
#include "myserver.h"
#include "mytimer.h"

MyCommands::MyCommands(QObject *parent) :
    QObject(parent)
{
}

void MyCommands::CheckServer(QString S)
{
    /*
     * Sprawdzanie rodzaju komunikatu (pierwsza litera polecenia)
     */
    if(S[0]=='M')
    Motors(S);
    if(S[0]=='B')
    {
        /*
         *  Zapytanie o stan baterii;
         */
        serial->send("b");
        qDebug()<<"Zapytanie o stan baterii.";
    }
    if(S[0]=='C')
    {
        /*
         * Nastawianie zegara cyklicznych zapytań o baterię.
         */
        QString I;
        int i=3, T;
        while(S[i]!='\n')
           {
           I[i-3]=S[i];
           i++;
           }
        T=I.toInt();
        if(T==0)
        {
        timer->TimerStop();
        qDebug()<<"Wylaczenie zegara.";
        }
        else
        {
        timer->TimerStart(T);
        qDebug()<<"Nastawienie zegara na:" << T << "milisekund";
        }
    }
}

void MyCommands::CheckSerial(char *S)
{
   /*
    * Sprawdzenie rodzaju komunikatu (pierwszy bit), oraz sformułowanie odpowiedzi dla serwera.
    */
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
    /*
     * Interpretacja polecenia, sformułowanie polecenia dla sterownika silników.
     */
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
       A.clear();
       A+="pl";
       A+=(char)Li;
       //serial->send("p");
       //serial->send("l");
       serial->send(A);
       A.clear();
       A+="pr";
       A+=(char)0;
       //serial->send("p");
       //serial->send("r");
       serial->send(A);
       A.clear();
    }


}

