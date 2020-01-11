#include "Maillage.h"

Maillage::Maillage(){
    while(!x.empty())
        x.pop_back();
    while(!y.empty())
        y.pop_back();
}

std::vector<double> Maillage::unifdiv(double a, long long unsigned N) {

    std::vector<double> res;

    res.push_back(0);

    for (int i = 1; i < N+1; i++) {
        res.push_back((a/N) + res[i-1]);
    }


    return res;

}

u64 Maillage :: numgb(u64 N, u64 M, u64 i, u64 j)
{
  if (i <= N && i >= 0 && j >= 0 && j <= M) {
    return j * N + i;
  }
  else
  {
    std::cout << "Numgb call not permited inputs, change please i & j" << '\n';
    return -1;
  }
}

void Maillage :: invnumgb(u64 N, u64 M, u64 k ,u64 &res_i, u64 &res_j)
{
if (k < 0 || k > (N * M)) {
  res_i = -1;
  res_j = -1;
  std::cout << "Numgb call not permited inputs, change please k" << std::endl;
  exit(0);
}

for (u64 i = 0; i < N; i++)  {
  for (u64 j = 0; j < M; j++) {
    if (numgb(N,M,i,j) == k) {
      res_i = i;
      res_j = j;
      return;
    }
  }
}

}

u64 Maillage :: num_int_gb(u64 N, u64 M, u64 k_int)
{
  u64 int_i,int_j;

  invnumgb(N, M, k_int, int_i, int_j);
  std::cout << "in func" << '\n';
  std::cout << "i : "<<int_i << " j : " << int_j << '\n';
  u64 k = numgb(N, M, int_i, int_j);
  std::cout << k << '\n';
  return k;
}


u64 Maillage::numint(u64 N, u64 M, u64 i, u64 j) {

    if (i <= N-1 && i >= 1 && j >= 1 && j <= M-1) {
            return ( (j-1) * (N-2) + (i-1));
    }
    else {
        std::cout << "Numgb call not permited inputs, change please i & j" << std::endl;
        return -1;
    }
}

void Maillage::invnumint(u64 N, u64 M, u64 k, u64 &res_i, u64 &res_j) {
    if( (k < 1) || (k > (N-2)*(M-2) ) ) {
        res_i = -1;
        res_j = -1;
        std::cout << "Numgb call not permited inputs, change please k" << std::endl;
        exit(0);
    }
    else {
        for ( int i = 1; i < N -1; i++ ) {
            for (int j = 1; j < M-1; j++ ) {
                if ( numint(N, M, i, j) == k ){
                    res_i = i;
                    res_j = j;
                  }
                std::cout << i <<" : " << j<< '\n';
            }
        }
    }
}

void Maillage::print() {

    std::cout << "X : " << std::endl;
    for (int i = 0; i < x.size(); i++) {
        std::cout << i << " : " << x[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Y : " << std::endl;
    for (int i = 0; i < y.size(); i++) {
        std::cout << i << " : " << y[i] << std::endl;
    }

}
