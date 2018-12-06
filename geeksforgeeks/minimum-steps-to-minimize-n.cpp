// https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition/0
/*
dp(i) = 1 + min(
  dp(i/2),
  dp(i/3),
  dp(i-1)
)
dp(1) = 0
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define None -1

// Tabulation
int solve(const int n){
  int M[n+1];

  M[1] = 0;
  for(int i=2; i<=n; i++){
    M[i] = M[i-1];

    if(i % 3 == 0)
      M[i] = min(M[i/3], M[i]);
    if(i % 2 == 0)
      M[i] = min(M[i/2], M[i]);

    M[i]++;
  }

  return M[n];
};

// Rescursion
class MinStep{
  public:
    int n;
    int *M;

    MinStep(int n_){
      n = n_;
      M = new int[n+1];
      M[1] = 0;
      for(int i=2; i<=n; i++)
        M[i] = None;
    };

    ~MinStep(){
      delete[] M;
    };

    int dp(int i){
      if(M[i] != None)
        return M[i];

      M[i] = dp(i-1);

      if(i % 3 == 0)
        M[i] = min(dp(i/3), M[i]);
      if(i % 2 == 0)
        M[i] = min(dp(i/2), M[i]);

      M[i]++;

      return M[i];
    };

    int solve(){
      return dp(n);
    };
};

int main(){
  int t, n;
  scanf("%d\n", &t);
  while(t--){
    scanf("%d\n", &n);

    printf("%d\n", solve(n));

    // MinStep ms(n);
    // printf("%d\n", ms.solve());
  }
  return 0;
}