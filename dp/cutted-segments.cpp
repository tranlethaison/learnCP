// https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <bits/stdc++.h>
using namespace std;

int maxSegments(int N, int x, int y, int z){
  int M[] = {x, y, z};
  int m = 3;

  /*
  If using arrays instead of vectors or pointers.
  Below TCs will fail. Why?
    2
    4000
    1 2 3
    3119
    3515 1021 7

    expected:
    4000
    11
  */
  // int T[N+1];
  // int S[N+1];

  // int *T = new int[N+1];
  // int *S = new int[N+1];
  vector<int> T(N+1);
  vector<int> S(N+1); // Keep track of which subprolems are valid. 
  
  T[0] = 0; // Base case
  S[0] = 1;

  for(int x=1; x<N+1; x++){
    T[x] = 0;
    for(y=0; y<m; y++){
      if(
        x >= M[y]
        && S[x - M[y]] == 1
      ){
        T[x] = max(T[x], 1 + T[x - M[y]]);
        S[x] = 1;
      }
    }
    // printf("%d ", T[x]);
  }
  // printf("\n");

  return T[N];
}

int main(){
  int t, N, x, y, z;
  scanf("%d\n", &t);
  while(t--){
    scanf("%d\n", &N);
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d\n", &z);
    printf("%d\n", maxSegments(N, x, y, z));
  }
  return 0;
}