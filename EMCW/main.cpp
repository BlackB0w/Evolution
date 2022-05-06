#include <QCoreApplication>
#include <QVector>
#include <iostream>
#include <evolution.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));
    Evolution ev;
    ev.run();
    return a.exec();
}
