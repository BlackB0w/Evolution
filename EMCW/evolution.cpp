#include "evolution.h"

void Evolution::getDataFromFile(QString path)
{
    std::ifstream rfile(path.toStdString());
    if (rfile.is_open()) {
        while(!rfile.eof()){
            double ef, l;
            rfile >> l;
            rfile >> ef;
            realEfs.push_back(ef);
            ls.push_back(l);
        }
        rfile.close();
    }
}

void Evolution::saveData(QString path, double min, double mid, double max)
{
    std::ofstream wfile(path.toStdString(),std::ios_base::app);
    if(wfile.is_open()){
        wfile << min <<"\t"<< mid <<"\t"<< max <<"\n";
        wfile.close();
    }
}

double Evolution::fitnessFunction(Chromosome ind)
{
    double ans = 0;
    for (int i = 0; i < realEfs.size();i++)
        ans+= sqrt( pow(realEfs[i]-ind.getA()*pow(ls[i],ind.getB()),2));
    ans = ans/realEfs.size();
    return ans;
}

QVector<Chromosome> Evolution::reproduction()
{
    QVector <double> rightBorders;
    QVector <Chromosome> tmppop;
    double sum = 0;
    for (int i =0; i <POP_NUM; i++)
        sum+= 1/fitnessFunction(population[i]);
    rightBorders.push_back(abs(1/fitnessFunction(population[0])/sum));
    for (int i =1; i < POP_NUM; i++)
        rightBorders.push_back(rightBorders[i-1] + abs(1/fitnessFunction(population[i])/sum));
    for(int i = 0; i<POP_NUM;i++){
        double random = REAL_RANDOM(0,1);
        int j = 0;
        for(; j < POP_NUM;j++)
            if(rightBorders[j] > random)
                break;
        tmppop.push_back(population[j]);
    }
    return tmppop;
}

QVector <Chromosome> Evolution::xover(Chromosome ind1, Chromosome ind2)
{
    QVector <Chromosome> newInds;
    Chromosome i1((W*ind1.getA() +(1-W)*ind2.getA()),(W*ind1.getB() +(1-W)*ind2.getB())),
            i2((W*ind2.getA() +(1-W)*ind1.getA()),(W*ind2.getB() +(1-W)*ind1.getB()));
    newInds.push_back(i1);
    newInds.push_back(i2);
    return newInds;
}

QVector <Chromosome> Evolution::reduce( QVector <Chromosome> tmppop)
{
    unsigned int maximal = 0;
    for (unsigned int i = 1; i < tmppop.size(); i++)
        if(fitnessFunction(tmppop[i]) >fitnessFunction(tmppop[maximal]))
            maximal = i;
    tmppop.removeAt(maximal);
    return tmppop;
}

Evolution::Evolution()
{
    getDataFromFile("C:\\Users\\BlackBow\\Desktop\\Lab_and_practice\\8_semestr\\EM_coursework\\data\\learn.txt");
    for (int i = 0; i < POP_NUM; i++){
        Chromosome chr(REAL_RANDOM(0,10),REAL_RANDOM(0,10));
        population.push_back(chr);
    }

}

void Evolution::run()
{

    unsigned int generation = 0;
    QString path = "C:\\Users\\BlackBow\\Desktop\\Lab_and_practice\\8_semestr\\EM_coursework\\data\\results\\errors.txt";
    std::ofstream wfile(path.toStdString(),std::ios_base::trunc);
    while(generation <MAX_GEN){
        QVector<Chromosome> tmppop = reproduction();
        int s = tmppop.size();
        for (int i = 0; i < s; i++){
            unsigned int ind1 = RANDOM(0,s),
                    ind2 =  RANDOM(0,s);
            while (ind1==ind2)
                ind2 = RANDOM(0,s);
            if (REAL_RANDOM(0,1)<XOVER_CHANCE){
                QVector <Chromosome> newInds = xover(tmppop[ind1],tmppop[ind2]);
                if(REAL_RANDOM(0,1) < MUTATION_CHANCE)
                    newInds[0].mutation();
                if(REAL_RANDOM(0,1) < MUTATION_CHANCE)
                    newInds[1].mutation();

                if(fitnessFunction(newInds[0])<fitnessFunction(newInds[1]))
                    tmppop.push_back(newInds[0]);
                else
                    tmppop.push_back(newInds[1]);
            }
        }
        while(tmppop.size()>POP_NUM)
            tmppop = reduce(tmppop);
        population=tmppop;
        generation++;

        int min = 0,max = 0;
        double mid = 0;

        for(int i = 1; i<POP_NUM;i++)
            if(fitnessFunction(population[min])>fitnessFunction(population[i]))
                min = i;

        for(int i = 1; i<POP_NUM;i++)
            if(fitnessFunction(population[max])<fitnessFunction(population[i]))
                max = i;

        for (int i = 0; i < POP_NUM; i++)
            mid+=fitnessFunction(population[i]);

        mid /= POP_NUM;
        aBest = population[min].getA();
        bBest = population[min].getB();

        double minimalValue = fitnessFunction(population[min]);
        double maximalValue = fitnessFunction(population[max]);
        saveData(path,minimalValue,mid,maximalValue);
        std::cout<< "generation " << generation << " complete\n";
    }
    Tests test(aBest,bBest);
}
