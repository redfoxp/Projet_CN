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

    for (int i = 1; i < N; i++) {
        res.push_back((a/(N-1)) + res[i-1]);
    }


    return res;

}
double Maillage :: numgb(u64 N, u64 M, u64 i, u64 j)
{
  if (i <= N && i >= 0 && j >= 0 && j <= M) {
    return (j) * N + i;
  }
  else
  {
    std::cout << "Numgb call not permited inputs, change please" << '\n';
    return -1.;
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
