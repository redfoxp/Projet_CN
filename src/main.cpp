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

  Maillage m;

  m.x = m.unifdiv(a, N);
  m.y = m.unifdiv(b, M);

  m.print();
  m.numgb(N,M,2,2);

  for (size_t j = 0; j < M; j++) {
    for (size_t i = 0; i < N; i++) {
      s.push_back(m.numgb(N,M,i,j));
      std::cout << m.numgb(N,M,i,j) << " " ;

    }
    std::cout << "" << '\n';
  }


  matplotlibcpp :: figure_size(1024,720);
  matplotlibcpp :: plot(s,"+");
  matplotlibcpp :: show();

  return 0;
}
