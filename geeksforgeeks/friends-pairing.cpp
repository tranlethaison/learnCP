// https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
/*
n = 3
1 2 3
1-2 3
1 2-3
2 1-3

---
n = 4
1 2 3 4
1-2 3 4
1-3 2 4
1 2-3 4
1-2 3-4
1-3 2-4
1-4 2-3
1 2-4 3
1 2 3-4
1-4 2 3

---
dp(1) = 1
dp(2) = 2
dp(3) = 4
dp(4) = 10

---
- Recurrence:
dp(i) = dp(i-1) + (i-1) * dp(i-2)
*/
#include <iostream>
using namespace std;

typedef unsigned long BUINT;

BUINT solve(const int n){
  BUINT M[n+1];
  M[1] = 1;
  M[2] = 2;
  for(int i=3; i<=n; i++){
    M[i] = (M[i-1] + (i-1) * M[i-2]) % (BUINT)(1e9 + 7);
  }
  return M[n];
};

int main(){
  int t, n;
  scanf("%d\n", &t);
  while(t--){
    scanf("%d\n", &n);
    printf("%llu\n", solve(n));
  }
  return 0;
}