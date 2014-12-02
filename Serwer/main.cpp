#include <QCoreApplication>
#include "myserver.h"
#include "myserial.h"
#include "mytimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    serwer = new MyServer;
    serial = new MySerial;
    timer = new MyTimer;
    return a.exec();
}
