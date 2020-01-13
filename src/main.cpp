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


//-----------------------------------------------------------//
//                          AFFICHAGE
  //matplotlibcpp :: figure_size(1024,720);
  //matplotlibcpp :: plot(k,"o");
  //matplotlibcpp :: plot(s,"+");

  //matplotlibcpp :: show();

  return 0;
}
