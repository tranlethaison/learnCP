// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include <bits/stdc++.h>
using namespace std;

class MCM{
  public:
    int n; // sizeof P
    int *P; // Matrices's dimension

    MCM(int n);
    ~MCM();
    int cost(int i, int k, int j);
    int topo();
};

MCM::MCM(int n){
  this->n = n;

  P = new int[n];
  for(int i=0; i<n; i++){
    scanf("%d", &P[i]);
  }
};

MCM::~MCM(){
  delete[] P;
};

int MCM::cost(int i, int k, int j){
  return P[i] * P[k+1] * P[j+1];
};

int MCM::topo(){
  int m = n - 1; // #matrices
  int M[m][m];

  for(int i=m-1; i>=0; i--){
    for(int j=i; j<=m-1; j++){
      if(i == j)
        M[i][j] = 0;
      else{
        M[i][j] = INT_MAX;
        for(int k=i; k<j; k++)
          M[i][j] = min(
            M[i][k] + M[k+1][j] + cost(i, k, j),
            M[i][j]
          );
      }
    }
  }

  return M[0][m-1];
};

int main(){
  int t, n;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d\n", &n);

    MCM mcm(n);
    printf("%d\n", mcm.topo());
  }
  return 0;
}