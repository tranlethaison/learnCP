// https://practice.geeksforgeeks.org/problems/ncr/0
/*
C(n, r) = C(n-1, r-1) + C(n-1, r)
C(n, 0) = C(n, n) = 1
*/
#include <bits/stdc++.h>
using namespace std;

int C(int n, int r){
  if(n < r)
    return 0;

  int a = (r < n-r) ? r : n-r; // C(n, r) = C(n, n-r)
  int M[n+1][a+1];

  for(int j=0; j<=a; j++){
    for(int i=j; i<=n; i++){
      if(i == j || j == 0)
        M[i][j] = 1;
      else
        M[i][j] = (M[i-1][j-1] + M[i-1][j]) % (int)(1e9 + 7);
    }
  }

  return M[n][a];
};

int main(){
  int t, n, r;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d %d\n", &n, &r);
    printf("%d\n", C(n, r));
  }
  return 0;
}