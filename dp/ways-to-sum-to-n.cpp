// https://practice.geeksforgeeks.org/problems/ways-to-sum-to-n/0
/*
dp(0) = 1
dp(n') = sum([
  n' - A[j]
  for j in range(m)
  if n' >= A[j]
])
*/
#include <iostream>
#include <string.h>
using namespace std;

typedef unsigned long long BUINT;

BUINT solve(int m, int n, int A[]){
  BUINT T[n+1];
  memset(T, 0, sizeof(T));

  T[0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<m; j++){
      if(i >= A[j])
        T[i] += T[i - A[j]];
    }
  }

  return T[n];
};

int main(){
  int t;
  scanf("%d\n", &t);

  while(t--){
  int m, n, *A;
  scanf("%d %d\n", &m, &n);

  A = new int[m];
  for(int i=0; i<m; i++){
    scanf("%d", &A[i]);
  }

  printf("%d\n", solve(m, n, A));

  delete[] A;
  }

  return 0;
}