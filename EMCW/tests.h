#ifndef TESTS_H
#define TESTS_H
#include <QVector>
#include <fstream>
#include <iostream>

class Tests
{
    QVector <double> ls;
    QVector <double> realEfs;
    void getDataFromFile(QString path);
    double ff(double a, double b);
    void saveData(QString path, QVector<double> fm);
public:
    Tests(double a, double b);
};

#endif // TESTS_H
