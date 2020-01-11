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
  m.numint(N,M,2,2);
  std::cout << "s : " << m.numint(N,M,1,1) << " pour i : "<< 1 << "  j : " << 1 << '\n';

  for (size_t j = 1; j < M-1; j++){
    for (size_t i = 1; i < N-1; i++)  {
      s.push_back(m.numint(N,M,i,j));
    }
  }

  matplotlibcpp :: figure_size(1024,720);
  matplotlibcpp :: plot(s,"+");
  matplotlibcpp :: show();

  std::cout << std::endl << m.numint(15, 75, 10, 30) << std::endl; 

  return 0;
}
