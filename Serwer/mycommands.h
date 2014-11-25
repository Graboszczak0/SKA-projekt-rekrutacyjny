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

signals:

public slots:
   static void Motors(QString S);

};

#endif // MYCOMMANDS_H
