#include "mycommands.h"

MyCommands::MyCommands(QObject *parent) :
    QObject(parent)
{
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
    if(S[1]=='V')
        qDebug()<< "Sterowanie predkoscia. Silnik lewy:"<< Li <<"Silnik prawy:"<< Ri;
       //wyslij do sterownikow {v}{L}{Li},{v}{R}{Ri}, wymagana zmiana z 16 bit na 8 bit.
    if(S[1]=='P')
       qDebug()<< "Sterowanie PWM. Silnik lewy:"<< Li <<"Silnik prawy:"<< Ri;
       //wyslij do sterownikow {p}{L}{Li},{p}{R}{Ri}, wymagana zmiana z 16 bit na 8 bit.


}
