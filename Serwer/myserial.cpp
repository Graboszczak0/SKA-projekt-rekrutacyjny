#include "myserial.h"
#include "mycommands.h"
#include <QDebug>
MySerial* serial;
QByteArray In;

MySerial::MySerial(QObject *parent) :
    QObject(parent)
{
    serial = new QSerialPort(this);
    /*
     * Ustawienia Portu szeregowego.
     */
    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(readyRead()));
}
void MySerial::readyRead()
{
    QByteArray T=serial->read(3-In.size());
    In+=T;
    //serial->waitForReadyRead(1000);In=serial->readAll();
    /*
     * Zbieranie 3 bitów, następnie rozpoznanie komunikatu.
     */
    if(In.size()==3)
    {
    MyCommands::CheckSerial(In);
    In.clear();
    }
}

void MySerial::send(QByteArray S)
{
    /*
     * Odpowiedź poprzez port szeregowy.
     */
    serial->write(S);
    serial->flush();
}
