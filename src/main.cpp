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

  std::cout << "Hello CN" << std::endl;
  std::vector<double> s;

  Maillage m;

  m.x = m.unifdiv(a, N);
  m.y = m.unifdiv(b, M);

  m.print();
  m.numgb(N,M,2,2);
  std::cout << "s : " << m.numgb(N,M,1,1) << " pour i : "<<1 << "  j : " << 1 << '\n';

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      s.push_back(m.numgb(N,M,i,j));
    }
  }

  matplotlibcpp :: figure_size(1024,720);
  matplotlibcpp :: plot(s,"+");
  matplotlibcpp :: show();

  return 0;
}
