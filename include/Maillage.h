#ifndef MAILLAGE_H
#define MAILLAGE_H

#include <vector>
#include <iostream>

class Maillage
{
public:

    std::vector<double> x;
    std::vector<double> y;
    
    Maillage();

    std::vector<double> unifdiv(double a, double N);
    double numint( N, M, i, j); 

    void print();

    ~Maillage(){}

};

#endif