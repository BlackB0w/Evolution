#include "chromosome.h"

double Chromosome::getA() const
{
    return a;
}

void Chromosome::setA(double newA)
{
    a = newA;
}

double Chromosome::getB() const
{
    return b;
}

void Chromosome::setB(double newB)
{
    b = newB;
}

void Chromosome::mutation()
{
    a *= 0.8;
    b *= 1.3;
}

Chromosome::Chromosome()
{

}

Chromosome::Chromosome(double a, double b)
{
    this->a = a;
    this->b = b;
}
