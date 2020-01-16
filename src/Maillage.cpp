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
    return -1;
  }
}

int Maillage :: invnumgb(u64 N, u64 M, u64 k ,u64 &res_i, u64 &res_j)
{
if (k < 0 || k > (N * M)) {
  res_i = -1;
  res_j = -1;
  //std::cout << "Invnumgb call not permited inputs, change please k" << std::endl;
  return -1;
}

for (u64 i = 0; i < N; i++)  {
  for (u64 j = 0; j < M; j++) {
    if (numgb(N,M,i,j) == k) {
      res_i = i;
      res_j = j;
      return 0;
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
        //std::cout << "Numint call not permited inputs, change please i & j" << std::endl;
        return -1;
    }
}

int Maillage::invnumint(u64 N, u64 M, u64 k, u64 &res_i, u64 &res_j) {
    if( (k < 0) || (k > (N-2)*(M-2) ) ) {
        res_i = -1;
        res_j = -1;
        //std::cout << "Invnumint call not permited inputs, change please k" << std::endl;
        return -1;
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
    return 0;
}

u64 Maillage :: num_gb_int(u64 N, u64 M, u64 s_gb)
{
  u64 i_gb,j_gb;
  u64 res = invnumgb(N, M, s_gb, i_gb, j_gb);
  if (res != -1) {
    return numint(N,M,i_gb,j_gb);
  }
  return -1;
}
//-------------------------------------------------------//
//                    Triangulation                      //
std::vector<std::vector<Triangle>> Maillage :: maillageTR(u64 N, u64 M)
{
  std::vector<std::vector<Triangle>> TRG(N*M);
  for (u64 i = 0; i < N*M; i++) {
    TRG[i].resize(2);
  }
  for (u64 i = 0; i < N *M; i++) {
      if (i % 2 == 1) {   //index impair
        TRG[i][0].n[0] = i + 1;//numgb(N, M, i+1, j);
        TRG[i][0].n[1] = i;//numgb(N, M, i,   j);        //T-
        TRG[i][0].n[2] = i + 1 + N;//numgb(N, M, i+1, j+1);

        TRG[i][1].n[0] = i + N + 1;//numgb(N, M, i, j+1);
        TRG[i][1].n[1] = i + 1 + N;//numgb(N, M, i+1, j +1);     //T+
        TRG[i][1].n[2] = i;//numgb(N, M, i,   j);

      }
      else      //index pair
      {
        TRG[i][0].n[0] = i;//numgb(N, M, i,   j);
        TRG[i][0].n[1] = i + 1;//numgb(N, M, i+1, j);        //T-
        TRG[i][0].n[2] = i + N;//numgb(N, M, i, j+1);

        TRG[i][1].n[0] = i + 1 + N;//numgb(N, M, i+1,j+1);
        TRG[i][1].n[1] = i + N;//numgb(N, M, i,  j+1);       //T+
        TRG[i][1].n[2] = i + 1;//numgb(N, M, i+1,  j);
      }
  }
  return TRG;
}
std::vector<std::vector<u64>> Maillage :: CalcMatBT(std::vector<u64> xs, std::vector<u64> ys)
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
//               Coordnees barycentriques                //

std::vector<std::vector<double>> Maillage :: GradGrad(std::vector<u64> xs, std::vector<u64> ys, u64 index_point, int Pos_triangle)
{
  std::vector<std::vector<double>> GrdGrd (3);
  for (int i = 0; i < 3; i++) {
      GrdGrd[i].resize(3);
  }
  double aire_trig = (abs (xs[1] - xs[0]) * abs(ys[2] - ys[0]))/2;
  std::vector<std::vector<u64>> BT = CalcMatBT(xs, ys);

  double determinant_BT = (BT[0][0] * BT[1][1]) - (BT[0][1] * BT[1][0]);

  std::vector<std::vector<double>> invBT(2);
  invBT[0].resize(2);
  invBT[1].resize(2);

  invBT[0][0] = BT[1][1] * (1/determinant_BT);
  invBT[1][1] = BT[0][0] * (1/determinant_BT);
  invBT[0][1] = - BT[0][1] * (1/determinant_BT);
  invBT[1][0] =  -BT[1][0] * (1/determinant_BT);



  GrdGrd[0][0] = ((-1 * BT[0][0] + -1* BT[1][0]) * (invBT[0][0] * -1 + invBT[0][1] * -1) + (-1 * BT[0][1] + -1 * BT[1][1]) * (invBT[1][0] * -1 + invBT[1][1] * -1)) * aire_trig;
  GrdGrd[0][1] = ((-1 * BT[0][0] + -1* BT[1][0]) * invBT[0][0]  + (-1 * BT[0][1] + -1 * BT[1][1]) * (invBT[1][0] ) ) * aire_trig;
  GrdGrd[0][2] = ((-1 * BT[0][0] + -1* BT[1][0]) * (invBT[0][1]) + (-1 * BT[0][1] + -1 * BT[1][1]) * ( invBT[1][1] )) * aire_trig;

  GrdGrd[1][0] = ((BT[0][0] ) * (invBT[0][0] * -1 + invBT[0][1] * -1) + (BT[0][1]) * (invBT[1][0] * -1 + invBT[1][1] * -1)) * aire_trig;
  GrdGrd[1][1] = ((BT[0][0] ) * (invBT[0][0] ) + ( BT[0][1] ) * (invBT[1][0] )) * aire_trig;
  GrdGrd[1][2] = ((BT[0][0] ) * (invBT[0][1]) + (BT[0][1] ) * (invBT[1][1] )) * aire_trig;

  GrdGrd[2][0] = ((BT[1][0]) * (invBT[0][0] * -1 + invBT[0][1] * -1) + (BT[1][1]) * (invBT[1][0] * -1 + invBT[1][1] * -1)) * aire_trig;
  GrdGrd[2][1] = ((BT[1][0]) * (invBT[0][0]) + (BT[1][1]) * (invBT[1][0])) * aire_trig;
  GrdGrd[2][2] = ((BT[1][0]) * (invBT[0][1]) + (BT[1][1]) * (invBT[1][1])) * aire_trig;



  return GrdGrd;
}



int Maillage :: DansTrg(std::vector<u64> xs, std::vector<u64> ys, u64 x, u64 y)
{
  int res = 0;
  u64 AB_x = xs[1] - xs[0];
  u64 AB_y = ys[1] - ys[0];

  u64 AM_x = x - xs[0];
  u64 AM_y = y - xs[0];

  u64 AC_x = xs[2] - xs[0];
  u64 AC_y = ys[2] - ys[0];

if ((AM_x ==  x * AB_x + y * AC_x) && (AM_y) == x * AB_y + y * AC_y) {
    res = 1;
}

return res;
}

//-------------------------------------------------------//
//                   Probleme discret                    //
std::vector<double>  Maillage ::  extendVec ( u64 N, u64 M ,std::vector<double> v)
{
  std::vector<double> v_tild(N * M);

  for (int i = 0; i < v.size(); i++) {
    v_tild[num_int_gb(N,M,i)] = v[i];
  }
  return v_tild;
}

std::vector<double> Maillage :: IntVec(u64 N,u64 M, std::vector<double> w, std::vector<u64> &k_int)
{
  std::vector<double> v ((N-2) * (M-2));
  u64 test;
  for (u64 i = 0; i < w.size(); i++) {
    test = num_gb_int(N,M,i);
    if (test != -1) {
      v[test] = w[i];
      k_int.push_back(test);
    }
  }
  return v;
}

std::vector<double> Maillage :: matvec(std::vector<double> v,u64 N, u64 M)
{
  std::vector<double> vv = extendVec(N,M,v);
  std::vector<double> ww(N * M);
  std::vector<u64> xs(3);
  std::vector<u64> ys(3);
  u64 x,y;
  u64 s,r;
  double GRAD2;
  double res;
  u64 K = N * M;
  std::vector<std::vector<Triangle>> TRG = maillageTR(N,M);
  for (u64 t = 0; t < K; t++) {
    for (int type_trig = 0; type_trig < 2; type_trig++) {
      invnumgb(N, M, TRG[t][type_trig].n[0] , x, y);
      xs[0] = x;
      ys[0] = y;
      invnumgb(N, M, TRG[t][type_trig].n[1] , x, y);
      xs[1] = x;
      ys[1] = y;
      invnumgb(N, M, TRG[t][type_trig].n[2] , x, y);
      xs[2] = x;
      ys[2] = y;

      std::vector<std::vector<u64>> BT = CalcMatBT(xs,ys);

      for (int a = 0; a < 3; a++) {
        s = TRG[t][type_trig].n[a];
        if (s < N*M) {
        res = 0;
        for (int b = 0; b < 3; b++) {
          r = TRG[t][type_trig].n[b];
          std::vector<std::vector<double>> v = GradGrad(xs, ys, t, type_trig);
          GRAD2 = v[a][b];
          res = res + vv[r] * GRAD2;
        }
        ww[s] = ww[s] + res;
        }
      }
    }
  }
  std::vector<double> w(N*M);
  std::vector<u64> k_int;
  w = IntVec(N, M, ww, k_int);

  return w;
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

void Maillage :: print_values_global_matrix(u64 N, u64 M ,std::vector<double> v)
{
  std::cout << '\n';
  for (u64 j = 0; j < M; j++) {
    for (u64 i = 0; i < N; i++) {
      if (v[j * N + i] == 0) {
        std::cout << v[j * N + i] << "    ";
      }
      else
      {
        std::cout << v[j * N + i] << " ";
      }

      /*
      if (v[j*N + i] != 0) {
        std::cout << v[j * N + i] << " ";
      }
      else
      {
        //std::cout << numgb(N,M,i,j) << " ";
      }
      */
    }
    std::cout << '\n';
  }
  std::cout  << '\n';
}

void Maillage :: print_values_int_matrix(u64 N,u64 M,std::vector<double> int_vec, std::vector<u64> &k_index)
{
  u64 cmpt = 0;
  std::cout << '\n';
  for (int j = 1; j < M-1; j++){
    for (int i = 1; i < N-1; i++)  {
      if (int_vec[cmpt] ==  0) {
        std::cout << int_vec[cmpt] <<"    ";
      }
      else
      {
        std::cout << int_vec[cmpt] <<" ";
      }

    /*
    if (int_vec[cmpt] != 0) {
      std::cout << int_vec[cmpt] <<" ";
    }
    else
    {
      std::cout << k_index[cmpt] << " ";
    }
    */
    cmpt++;
    }

    std::cout << '\n';
  }

}
