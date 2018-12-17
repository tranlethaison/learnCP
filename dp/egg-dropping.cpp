// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
/*
- State:
  n': number of eggs
  k': number of floors

- Guess:
  Does floor i break eggs?

- Recurrence:
  Minimum number of attemps in worst case:
  dp(n', k') = 1 + min(
    max(
      dp(n', k'-x),        # not break 
      dp(n'-1, x-1)       # break
    )
    for x in range(1, k'+1)
  )

- Topo:
  T[n+1][k+1]
  
  for j in range(1, k+1):
    for i in range(1, n+1):
      if(i == 1) or (j == 1):
        T[i][j] = j;
      else:
        
- Original problem:
    T[n][k]
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k){
  int T[n+1][k+1];

  for(int j=1; j<=k; j++)
    T[1][j] = j;

  for(int i=1; i<=n; i++){
    T[i][0] = 0;
    T[i][1] = 1;
  }

  int tix;
  for(int i=2; i<=n; i++){
    for(int j=2; j<=k; j++){
      T[i][j] = INT_MAX;
      for(int x=2; x<=j; x++){
        tix = 1 + max(
          T[i][j-x],
          T[i-1][x-1]
        );

        T[i][j] = min(T[i][j], tix);
      }
    }
  }

  return T[n][k];
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, k;
  cin >> t;
  while(t--){
    cin >> n >> k;
    cout << solve(n, k) << "\n";
  }

  return 0;
}