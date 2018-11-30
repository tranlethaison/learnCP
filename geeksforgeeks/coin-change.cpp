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
    // printf("%d ", S[i]);
  }
  // printf("\n");
};

int CoinChange::solve(){
  return 0;
};

int main(){
  int t;
  scanf("%d\n", &t);

  while(t--){
    CoinChange cc;
    scanf("%d\n", &cc.m);
    cc.getS();
    scanf("%d\n", &cc.n);
    printf("%d\n"), cc.solve();
  }
  return 0;
}