#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class MySerial : public QObject
{
    Q_OBJECT
public:
    explicit MySerial(QObject *parent = 0);
    void send(QByteArray S);

signals:

public slots:
    void readyRead();


private:
    QSerialPort *serial;

};

extern MySerial* serial;

#endif // MYSERIAL_H
