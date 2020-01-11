#include <stdlib.h>
#include <stdio.h>

#include <iostream>

#include "Maillage.h"

int main(int argc, char const *argv[]) {

  std::cout << "Hello CN" << std::endl;

  Maillage m;

  m.x = m.unifdiv(10, 9);
  m.y = m.unifdiv(6.4, 3);

  m.print();

  std::cout << std::endl << m.numint(15, 75, 10, 30) << std::endl; 

  return 0;
}
