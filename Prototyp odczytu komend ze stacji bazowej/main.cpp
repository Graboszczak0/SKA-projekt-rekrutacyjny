#include <QCoreApplication>
#include <QString>
#include <QDebug>

void Silniki(QString S)
{
     QString L, R;
     if(S[1]=='V')
     {
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
        qDebug()<< "Sterowanie predkoscia. Silnik lewy:"<< Li <<"Silnik prawy:"<< Ri;
        //wyslij do sterownikow {v}{Ri}{Li}, wymagana zmiana z 16 bit na 8 bit.
     }
     if(S[1]=='P')
     {
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
        qDebug()<< "Sterowanie PWM. Silnik lewy:"<< Li <<"Silnik prawy:"<< Ri;
        //wyslij do sterownikow {p}{Ri}{Li}, wymagana zmiana z 16 bit na 8 bit.
     }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Wejscie (Musi byc zakonczone "\n"
    QString S1="MV;99";
    QString S2=";123\n";
    while(S1[S1.size()-1]!='\n')
    {
    //w razie niekompletnosci komendy, wczytywać dalej (S2).
    S1=S1+S2;
    }
    qDebug()<<S1;
    if(S1[0]=='M')
    {
       Silniki(S1);
    }
    if(S1[0]=='B')
    {
        qDebug()<<"Wyslano zapytanie o stan baterii";
        //wyslij do sterownikow {b}
    }
    return a.exec();
}
