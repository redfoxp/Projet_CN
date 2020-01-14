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

u64 index_trg_i = 2;
u64 index_trg_j = 2;

Triangle trig = m.maillageTR(N,M)[index_trg_i][index_trg_j];

std::cerr << "TRG i = "<< index_trg_i << " j = "<< index_trg_j << " coordonees : Global " << '\n' <<
      "                T-      n1 :   " << trig.n1_l <<'\n' <<
      "                        n2 :   " << trig.n2_l << '\n' <<
      "                        n3 :   " << trig.n3_l << '\n' <<
      "                T+      n1 :   " << trig.n1_u <<'\n' <<
      "                        n2 :   " << trig.n2_u << '\n' <<
      "                        n3 :   " << trig.n3_u << '\n';

// TEST ajout valeurs a la matrice
std::vector<double> v (5);
std::vector<u64> k_int (5);
k_int[0] = 42;
k_int[1] = 43;
k_int[2] = 44;
k_int[3] = 45;
k_int[4] = 46;

v[0] = 0.2;
v[1] = 0.21;
v[2] = 0.3;
v[3] = 0.31;
v[4] = 0.4;

std::vector<double> Global_vec = m.extendVec(N,M,v,k_int);
m.print_values_global_matrix(N,M,Global_vec);

std::vector<u64> k_index;
std::vector<double> Int_vec = m.IntVec(N,M,Global_vec,k_index);

m.print_values_int_matrix(N,M,Int_vec,k_index);


//-----------------------------------------------------------//
//                          AFFICHAGE
  //matplotlibcpp :: figure_size(1024,720);
  //matplotlibcpp :: plot(k,"o");
  //matplotlibcpp :: plot(s,"+");

  //matplotlibcpp :: show();

  return 0;
}
