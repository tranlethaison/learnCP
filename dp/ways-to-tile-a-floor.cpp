// https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0
/*
dp(i) = dp(i-1) + dp(i-2)
dp(1) = 1
dp(2) = 2 
*/
#include <bits/stdc++.h>
using namespace std;

unsigned long solve(int w){
  unsigned long M[w+1];

  M[1] = 1;
  M[2] = 2;
  for(int i=3; i<=w; i++){
    M[i] = M[i-1] + M[i-2];
  }

  return M[w];
};

int main(){
  int t, w;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d\n", &w);
    printf("%lu\n", solve(w));
  }
  return 0;
}