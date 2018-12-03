// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include <bits/stdc++.h>
using namespace std;

class MCM{
  public:
    int n;
    int *P;

    MCM(int n);
    int cost(int l);
    int solve();
};

MCM::MCM(int n){
  this->n = n;

  P = new int[n];
  for(int i=0; i<n; i++){
    scanf("%d", &P[i]);
  }
};

int MCM::cost(int l){

};

int MCM::solve(){
  int M[n][n];

  for(int i=n-1; i>=0; i--){
    for(int j=i; j<n; j++){
      if(i == j)
        M[i][j] = 0;
      else{
        int min_cost_l = 0;
        for(int l=i+1; l<=j; l++)
          min_cost_l = min(
            M[i][l] + M[l][j] + cost(l),
            min_cost_l
          );
        M[i][j] = min_cost_l;
      }
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }

  return M[0][n-1];
};

int main(){
  int t, n;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d\n", &n);

    MCM mcm(n);
    printf("%d\n", mcm.solve());
  }
  return 0;
}