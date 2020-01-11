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

double Maillage :: numgb(u64 N, u64 M, u64 i, u64 j)
{
  if (i <= N && i >= 0 && j >= 0 && j <= M) {
    return j * N + i;
  }
  else
  {
    std::cout << "Numgb call not permited inputs, change please" << '\n';
    return -1.;
  }
}

double Maillage::numint(u64 N, u64 M, u64 i, u64 j) {
    
    if (i <= N && i >= 1 && j >= 1 && j <= M) {
            return ( (j-1) * (N-2) + (i-1)); 
    }
    else {
        std::cout << "erreur i ou j mauvais interval" << std::endl;
        return -1;
    }
}

void Maillage::invnumint(u64 N, u64 M, u64 k, u64 &res_i, u64 &res_j) {
    if( (k < 1) || (k > (N-1)*(M-1) ) ) {
        res_i = -1;
        res_j = -1;
        std::cout << "erreur K mauvais interval" << std::endl;
        return;
    }
    else {
        for ( int i = 2; i <= N; i++ ) {
            for (int j = 2; j <= M; j++ ) {
                if ( numint(N, M, i, j) == k ){
                    res_i = i;
                    res_j = j;
                    return;
                }
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
