// https://practice.geeksforgeeks.org/problems/gold-mine-problem/0
/*
- Subproblems: Prefix G[:i][:j] (Dimensions: n*m)
- Guess: the predecessor of cell[i][j]
- Recurrent:
  dp(i, j) = 
    G[i][j] +
    max(
      dp(i, j-1), dp(i+1, j-1), dp(i-1, j-1)
    )
- Topo:
  for j in range(m):
    for i in range(n):

- Original problem:
  max(
    dp(i, m-1) for i in range(n)
  )
*/
#include <bits/stdc++.h>
using namespace std;

class GMP{
  public:
    int n, m;
    int **G;

    GMP(int n, int m);
    int solve();
};

GMP::GMP(int n, int m){
  this->n = n;
  this->m = m;

  G = new int*[n];
  for(int i=0; i<n; i++){
    G[i] = new int[m];
    for(int j=0; j<m; j++)
      scanf("%d", &G[i][j]);
  }
};

int GMP::solve(){
  int M[n][m];
  for(int j=0; j<m; j++){
    for(int i=0; i<n; i++){
      if(j == 0)
        M[i][j] = G[i][j];
      else if(n == 1)
        M[i][j] = G[i][j] + M[i][j-1];
      else if(i == 0)
        M[i][j] = G[i][j] + max({M[i][j-1], M[i+1][j-1]});
      else if(i == n-1)
        M[i][j] = G[i][j] + max({M[i][j-1], M[i-1][j-1]});
      else
        M[i][j] = G[i][j] + max({M[i][j-1], M[i+1][j-1], M[i-1][j-1]});
    }
  }

  int ori = 0;
  for(int i=0; i<n; i++)
    ori = max(ori, M[i][m-1]);

  return ori;
};

int main(){
  int t, n, m;
  scanf("%d\n", &t);
  while(t--){
    scanf("%d %d\n", &n, &m);
    GMP gmp(n, m);
    printf("%d\n", gmp.solve());
  }
  return 0;
}