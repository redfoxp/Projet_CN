#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "types.h"
class Triangle {
public:
  u64 n1;
  u64 n2;
  u64 n3;

  Triangle ()
  {
    n1 = 0;
    n2 = 0;
    n3 = 0;
  }
  ~Triangle (){}
};

#endif
