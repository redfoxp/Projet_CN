#include <stdlib.h>
#include <stdio.h>

#include <iostream>

#include "Maillage.h"
#include "matplotlibcpp.h"

#ifndef CONSTANT
#define CONSTANT
#define a 5
#define b 5
#define N 5
#define M 5

#endif

int main(int argc, char const *argv[]) {

  std::cout << "Hello CN" << std::endl;
  std::vector<double> s;
  std::vector<double> k;

  Maillage m;

  m.x = m.unifdiv(a, N);
  m.y = m.unifdiv(b, M);

  m.print();
  std::cout << "K : points interieur " << '\n';
  for (int j = 1; j < M-1; j++){
    for (int i = 1; i < N-1; i++)  {
      k.push_back(m.numint(N,M,i,j));
      std::cout << m.numint(N,M,i,j) << " " ;

    }
    std::cout << "" << '\n';

  }

std::cout << "S : points global " << '\n';
  for (size_t j = 0; j < M; j++) {
    for (size_t i = 0; i < N; i++) {
      s.push_back(m.numgb(N,M,i,j));
      std::cout << m.numgb(N,M,i,j) << " " ;

    }
    std::cout << "" << '\n';
  }

u64 test_i,test_j;

m.invnumgb(N,M,12,test_i,test_j);
std::cerr << "recherche k = 12 : "<< test_i << " : " << test_j << '\n';

  matplotlibcpp :: figure_size(1024,720);
  matplotlibcpp :: plot(k,"o");
  matplotlibcpp :: plot(s,"+");

  matplotlibcpp :: show();

  return 0;
}
