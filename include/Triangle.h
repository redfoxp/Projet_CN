#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "types.h"
class Triangle {
public:
  std::vector<u64> n;

  Triangle ()
  {
    n.resize(3);
    n[0] = 0;
    n[1] = 0;
    n[2] = 0;
  }
  ~Triangle (){}
};

#endif
