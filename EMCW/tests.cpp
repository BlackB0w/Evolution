#include "tests.h"

void Tests::getDataFromFile(QString path)
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

double Tests::ff(double a, double b)
{
    double ans = 0;
    for (int i = 0; i < realEfs.size();i++)
        ans+= sqrt( pow(realEfs[i]-a*pow(ls[i],b),2));
    ans = ans/realEfs.size();
    return ans;
}

void Tests::saveData(QString path, QVector<double> fm)
{
    std::ofstream wfile(path.toStdString(),std::ofstream::out | std::ios_base::trunc);
    if(wfile.is_open()){
        int size = fm.size();
        for (int i = 0; i < size; i++)
        wfile << realEfs[i] <<"\t"<< fm[i] <<"\n";
        wfile.close();
    }
}

Tests::Tests(double a, double b)
{
    getDataFromFile("C:\\Users\\BlackBow\\Desktop\\Lab_and_practice\\8_semestr\\EM_coursework\\data\\test.txt");
    std::cout << "a: " << a <<" b: " << b <<"\n";
    QVector <double> fm(realEfs.size(),0);
    for (int i = 0; i < realEfs.size();i++){
        fm[i] = a*pow(ls[i],b);
        std::cout <<"L:"<<ls[i] << "\tReal f: " << realEfs[i] << "\t model f: " << fm[i] << "\n";
    }
    std::cout << "Fitness function value: " << ff(a,b)<<"\n";
    saveData("C:\\Users\\BlackBow\\Desktop\\Lab_and_practice\\8_semestr\\EM_coursework\\data\\results\\results.txt",fm);
}
