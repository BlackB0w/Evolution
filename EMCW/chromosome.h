#ifndef CHROMOSOME_H
#define CHROMOSOME_H


class Chromosome
{
    double a;
    double b;
public:
    Chromosome();
    Chromosome(double a, double b);
    double getA() const;
    void setA(double newA);
    double getB() const;
    void setB(double newB);
    void mutation();
};

#endif // CHROMOSOME_H
