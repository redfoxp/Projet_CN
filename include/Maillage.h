#ifndef MAILLAGE_H
#define MAILLAGE_H

#include <vector>
#include <iostream>

#include "Triangle.h"
#include "types.h"

class Maillage
{
public:

    std::vector<double> x;
    std::vector<double> y;

    Maillage();

    std::vector<double> unifdiv(double a, u64 N);

    //-------------------------------------------------------//
    //                     Numerotation                      //
    u64 numgb(u64 N, u64 M, u64 i, u64 j);
    void invnumgb(u64 N, u64 M, u64 k ,u64 &res_i, u64 &res_j);
    u64 num_int_gb(u64 N, u64 M, u64 k_int);

    u64 numint(u64 N, u64 M, u64 i, u64 j);
    void invnumint(u64 N, u64 M, u64 k, u64 &res_i, u64 &res_j);
    u64 num_gb_int(u64 N, u64 M, u64 s_gb);

    //-------------------------------------------------------//
    //                    Triangulation                      //
    std::vector< std::vector<Triangle>> maillageTR(u64 N, u64 M);
    std::vector<std::vector<u64>> CalcMatBT(std::vector<u64> xs, std::vector<u64> ys);

    //-------------------------------------------------------//
    //                      Affichage                        //
    void print();
    void print_num_gb(u64 N, u64 M);
    void print_num_int(u64 N, u64 M);

    ~Maillage(){}

};

#endif
