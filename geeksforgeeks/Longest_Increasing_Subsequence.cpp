//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;

int t, n;

int next(int i, int n, const int S[]){
  for(int j=i+1; i<n; i++){
    if(S[j] > S[i])
      return j;
  }
  return -1;
};

int lis_res(int i, int n, const int S[], int M[]){
  // printf("%d | S%d | M%d\n", i, S[i], M[i]);

  if(M[i] != -1)
    return M[i];

  int f;
  if(i == n - 2){
    if(next(i, n, S) == i + 1)
      f = 1;
    else
      f = 0;
  }
  else if(next(i, n, S) == -1)
    f = lis_res(i+1, n, S, M);
  else
    f = max(
      lis_res(i+1, n, S, M),
      lis_res(next(i, n, S), n, S, M) + 1
    );

  M[i] = f;
  return f;
};

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);

    int S[n];
    for(int i=0; i<n; i++)
      scanf("%d", &S[i]);

    int M[n+1]; //memory
    memset(M, -1, sizeof M);

    printf("%d\n", lis_res(0, n, S, M));
    // printf("----\n");
  }
  return 0;
}