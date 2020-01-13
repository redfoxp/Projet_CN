#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "types.h"
class Triangle {
public:
  u64 n1_u;
  u64 n2_u; //u pour upper pour T+
  u64 n3_u;

  u64 n1_l;
  u64 n2_l; //l pour lower pour T-
  u64 n3_l;

  Triangle ()
  {
    n1_l = 0;
    n1_u = 0;

    n2_l = 0;
    n2_u = 0;
    
    n3_l = 0;
    n3_u = 0;
  }
  ~Triangle (){}
};

#endif
