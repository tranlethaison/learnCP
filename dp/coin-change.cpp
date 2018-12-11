// https://practice.geeksforgeeks.org/problems/coin-change/0
#include <bits/stdc++.h>
using namespace std;

class CoinChange{
  public:
    int m; // size of array S
    int* S; // array of coin kinds
    int n; // n cents

    void getS();
    int solve();
};

void CoinChange::getS(){
  S = new int[m];
  for(int i=0; i<m; i++){
    scanf("%d", &S[i]);
    // printf("%02d ", S[i]);
  }
  // printf("\n");
};

int CoinChange::solve(){
  int M[m][n+1];

  for(int i=0; i<m; i++){
    for(int j=0; j<=n; j++){
      if(j == 0){
        M[i][j] = 1;
      }
      else if (j - S[i] < 0){
        if(i == 0)
          M[i][j] = 0;
        else
          M[i][j] = M[i-1][j];
      }
      else{
        if(i == 0)
          M[i][j] = (j % S[i] == 0) ? 1 : 0;
        else
          M[i][j] = M[i][j - S[i]] + M[i-1][j];
      }
      // printf("%02d ", M[i][j]);
    }
    // printf("\n");
  }

  return M[m-1][n];
};

int main(){
  int t;
  scanf("%d\n", &t);

  while(t--){
    CoinChange cc;
    scanf("%d\n", &cc.m);
    cc.getS();
    scanf("%d\n", &cc.n);
    printf("%d\n", cc.solve());
  }
  return 0;
}