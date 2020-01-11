#ifndef MAILLAGE_H
#define MAILLAGE_H

#include <vector>
#include <iostream>

#include "types.h"

class Maillage
{
public:

    std::vector<double> x;
    std::vector<double> y;

    Maillage();

    std::vector<double> unifdiv(double a, u64 N);
    double numgb(u64 N, u64 M, u64 i, u64 j);
    void print();

    ~Maillage(){}

};

#endif
