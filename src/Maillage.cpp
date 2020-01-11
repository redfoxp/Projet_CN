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

    for (int i = 1; i < N-1; i++) {
        res.push_back((a/(N-1)) + res[i-1]);
    }

    res.push_back(a);

    return res;

}

double Maillage :: numgb(u64 N, u64 M, u64 i, u64 j)
{
    return 0.;
}

double Maillage::numint(u64 N, u64 M, u64 i, u64 j) {
    
    if ( ( i < 2 || i > N ) || ( j < 2 || j > M ) ) {
            std::cout << "erreur i ou j mauvais interval" << std::endl;
            return -1;
    }

    return ( (j-2) * (N-1) + i-1 ); 
}

void Maillage::invnumint(u64 N, u64 M, u64 k, u64 &res_i, u64 &res_j) {
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
