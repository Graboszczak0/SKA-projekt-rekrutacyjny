#include "mytimer.h"
#include "myserial.h"
MyTimer *timer;

MyTimer::MyTimer(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()),this, SLOT(MyTimerSlot()));
}

void MyTimer::TimerStart(int a)
{
    /*
     * Ustawianie zegaru timera.
     */
    timer->start(a);
}

void MyTimer::MyTimerSlot()
{
    /*
     *  Cykliczne zapytania o stan baterii.
     */
    serial->send("b");
}
