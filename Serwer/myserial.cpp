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
    serial->setPortName("COM4");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(readyRead()));
}
void MySerial::readyRead()
{
    //serial->waitForReadyRead(0);
    In=serial->readAll();

 //  qDebug()<<"Receiving this frame in hex"<<In.toHex();
// qDebug()<<"Receiving this frame in string"<<In;
    /*
     * Zbieranie 3 bitów, następnie rozpoznanie komunikatu.
     */
    //qDebug()<<In;
    MyCommands::CheckSerial((char*)In.constData());
}

void MySerial::send(QByteArray S)
{
    /*
     * Odpowiedź poprzez port szeregowy.
     */
    //qDebug()<<"Sending this frame"<<S.toHex();
    serial->write(S);
    serial->flush();
}
