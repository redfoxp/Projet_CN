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

//-------------------------------------------------------//
//                     Numerotation                      //

u64 Maillage :: numgb(u64 N, u64 M, u64 i, u64 j)
{
  if (i < N && i >= 0 && j >= 0 && j < M) {
    return j * N + i;
  }
  else
  {
    std::cout << "Numgb call not permited inputs, change please i & j" << '\n';
    exit(0);
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

  invnumint(N, M, k_int, int_i, int_j);

  return numgb(N, M, int_i, int_j);
}


u64 Maillage::numint(u64 N, u64 M, u64 i, u64 j) {

    if (i < N-1 && i >= 1 && j >= 1 && j < M-1) {
            return ( (j-1) * (N-2) + (i-1));
    }
    else {
        std::cout << "Numgb call not permited inputs, change please i & j" << std::endl;
        exit(0);
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
            }
        }
    }
}

u64 Maillage :: num_gb_int(u64 N, u64 M, u64 s_gb)
{
  u64 i_gb,j_gb;
  invnumgb(N, M, s_gb, i_gb, j_gb);
  return numint(N,M,i_gb,j_gb);
}
//-------------------------------------------------------//
//                    Triangulation                      //
std::vector<std::vector<Triangle>> Maillage :: maillageTR(u64 N, u64 M)
{
  std::vector< std::vector<Triangle>> TRG(N);
  for (size_t i = 0; i < M; i++) {
    TRG[i].resize(M);
  }
  for (u64 i = 0; i < N-1; i++) {
    for (u64 j = 0; j < M-1; j++) {
      if (i % 2 == 1) {
        TRG[i][j].n1_l = numgb(N, M, i,   j);
        TRG[i][j].n2_l = numgb(N, M, i+1, j);
        TRG[i][j].n3_l = numgb(N, M, i+1, j+1);

        TRG[i][j].n1_u = numgb(N, M, i,   j);
        TRG[i][j].n2_u = numgb(N, M, i+1, j +1);
        TRG[i][j].n3_u = numgb(N, M, i, j+1);

      }
      else
      {
        TRG[i][j].n1_l = numgb(N, M, i,   j);
        TRG[i][j].n2_l = numgb(N, M, i+1, j);
        TRG[i][j].n3_l = numgb(N, M, i, j+1);

        TRG[i][j].n1_u = numgb(N, M, i,  j+1);
        TRG[i][j].n2_u = numgb(N, M, i+1,j+1);
        TRG[i][j].n3_u = numgb(N, M, i+1,  j);
      }
    }
  }
  return TRG;
}
std::vector<std::vector<u64>> CalcMatBT(std::vector<u64> xs, std::vector<u64> ys)
{
  std::vector<std::vector<u64>> BT(2);
  BT[0].resize(2);
  BT[1].resize(2);

  BT[0][0] = xs[1] - xs[0]; //k = 2
  BT[0][1] = ys[1] - ys[0];

  BT[1][0] = xs[2] - xs[0]; //k = 3
  BT[1][1] = ys[2] - ys[0];

  return BT;
}



//-------------------------------------------------------//
//                      Affichage                        //

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

void Maillage ::  print_num_gb(u64 N,u64 M)
{
  std::vector<double> s;

  std::cout << '\n' << "S : points global " << '\n';
    for (size_t j = 0; j < M; j++) {
      for (size_t i = 0; i < N; i++) {
        s.push_back(numgb(N,M,i,j));
        std::cout << numgb(N,M,i,j) << " " ;

      }
      std::cout << '\n';
    }
}
void Maillage ::  print_num_int(u64 N, u64 M)
{
  std::vector<double> k;

    std::cout <<'\n' << "K : points interieur " << '\n';
    for (int j = 1; j < M-1; j++){
      for (int i = 1; i < N-1; i++)  {
        k.push_back(numint(N,M,i,j));
        std::cout << numint(N,M,i,j) << " " ;

      }
      std::cout << '\n';

    }
    std::cout << '\n';
}
