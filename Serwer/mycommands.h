#ifndef MYCOMMANDS_H
#define MYCOMMANDS_H

#include <QObject>
#include <QString>
#include <QDebug>


class MyCommands : public QObject
{
    Q_OBJECT
public:
    explicit MyCommands(QObject *parent = 0);
    static void Motors(QString S);
    static void CheckServer(QString S);
    static void CheckSerial(char *S);

signals:

public slots:


};

#endif // MYCOMMANDS_H
