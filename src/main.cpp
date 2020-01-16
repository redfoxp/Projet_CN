#include <stdlib.h>
#include <stdio.h>

#include <iostream>

#include "Maillage.h"
#include "matplotlibcpp.h"

#ifndef CONSTANT
#define CONSTANT
#define a 10
#define b 10
#define N 10
#define M 10

#endif

int main(int argc, char const *argv[]) {

  Maillage m;

  m.x = m.unifdiv(a, N);
  m.y = m.unifdiv(b, M);

  m.print_num_gb(N,M);
  m.print_num_int(N,M);

//-----------------------------------------------------------//
//                          TESTS                            //

u64 test_i,test_j;
u64 test_pos_int = 3;
u64 test_pos_gb = 13;
m.invnumint(N,M,test_pos_int,test_i,test_j);

std::cerr << "interieur " << test_pos_int << ": i = "<< test_i << " j = " << test_j << '\n';

std::cout << "interieur " << test_pos_int << " global    : "<< m.num_int_gb(N,M,test_pos_int) << '\n';

std::cout << "global    " << test_pos_gb  << " interieur : " << m.num_gb_int(N,M,test_pos_gb)<<'\n';

u64 index_trg = 2;

std::vector<Triangle> trig = m.maillageTR(N,M)[index_trg];

std::cerr << "TRG  = "<< index_trg<< " coordonees : Global " << '\n' <<
      "                T-      n1 :   " << trig[0].n[0] << '\n' <<
      "                        n2 :   " << trig[0].n[1] << '\n' <<
      "                        n3 :   " << trig[0].n[2] << '\n' <<
      "                T+      n1 :   " << trig[1].n[0] << '\n' <<
      "                        n2 :   " << trig[1].n[1] << '\n' <<
      "                        n3 :   " << trig[1].n[2] << '\n';

// TEST ajout valeurs a la matrice
std::vector<double> v (5);

v[0] = 0.2;
v[1] = 0.21;
v[2] = 0.3;
v[3] = 0.31;
v[4] = 0.4;

std::vector<double> Global_vec = m.extendVec(N,M,v);
m.print_values_global_matrix(N,M,Global_vec);

std::vector<u64> k_index;
std::vector<double> Int_vec = m.IntVec(N,M,Global_vec,k_index);

m.print_values_int_matrix(N,M,Int_vec,k_index);
//      TEST MAT VEC

std::vector<double> Global_matvec = m.matvec(Int_vec,N,M);
//m.print_values_global_matrix(N,M,Global_matvec);

//-----------------------------------------------------------//
//                          AFFICHAGE
  //matplotlibcpp :: figure_size(1024,720);
  //matplotlibcpp :: plot(k,"o");
  //matplotlibcpp :: plot(s,"+");

  //matplotlibcpp :: show();

  return 0;
}
