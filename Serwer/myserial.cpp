#include "myserial.h"
#include "mycommands.h"

MySerial* serial;
int i;
char In[3];

MySerial::MySerial(QObject *parent) :
    QObject(parent)
{
    serial = new QSerialPort(this);
    serial->setPortName("COM1");
    //serial->setBaudRate(QSerialPort::Baud9600);
    //serial->setDataBits(QSerialPort::Data8);
    //serial->setParity(QSerialPort::NoParity);
    //serial->setStopBits(QSerialPort::OneStop);
    //serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    i=0;
    connect(serial,SIGNAL(readyRead()),this,SLOT(readyRead()));
}
void MySerial::readyRead()
{
    serial->waitForReadyRead(100);
    serial->getChar(&In[i]);
    i++;
    if(i==3)
    {
        i=0;
        MyCommands::CheckSerial(In);
    }
}

void MySerial::send(QByteArray S)
{
    qDebug()<<(int)S[0];
    serial->write(S);
}
