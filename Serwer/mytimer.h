#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = 0);
    void TimerStart(int);
    QTimer *timer;

signals:

public slots:
    void MyTimerSlot();

private:


};

extern MyTimer* timer;

#endif // MYTIMER_H
