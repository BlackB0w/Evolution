#ifndef EVOLUTION_H
#define EVOLUTION_H
#include <chromosome.h>
#include <params.h>
#include <QVector>
#include <fstream>
#include <iostream>
#include <tests.h>
class Evolution
{
    double aBest;
    double bBest;
    QVector <double> ls;
    QVector <double> realEfs;
    QVector <Chromosome> population;

    void getDataFromFile(QString path);
    void saveData(QString path,double min, double mid, double max);
    double fitnessFunction(Chromosome ind);
    QVector <Chromosome> reproduction();
    QVector <Chromosome> xover(Chromosome ind1, Chromosome ind2);
    QVector <Chromosome> reduce( QVector <Chromosome> tmppop);
public:
    Evolution();
    void run();
};

#endif // EVOLUTION_H
