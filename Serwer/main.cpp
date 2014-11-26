#include <QCoreApplication>
#include "myserver.h"
#include "myserial.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    serwer = new MyServer;
    serial = new MySerial;
    return a.exec();
}
