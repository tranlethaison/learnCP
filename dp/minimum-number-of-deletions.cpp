// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions/0
/*
- Subproblems:
  substring S[i:j]

- Guess:
  If edges chars are equal, keep both of them.
  Else, guess which edge to remove?

- Recurrence:
  if S[i] = S[j]:
    dp(i, j) <- dp(i+1, j-1)
  else:
    dp(i, j) <- 1 + min(
      dp(i+1, j),
      dp(i, j-1)
    )

- Topo:
  if i = j:
    dp(i, j) <- 0
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define None -1

class MD{
public:
  int n;
  string S;
  int **M;

  MD(int n_, string S_): n(n_), S(S_){
    M = new int*[n];
    for(int i=0; i<n; i++){
      M[i] = new int[n];
      for(int j=0; j<n; j++)
        M[i][j] = None;
    }
  };

  ~MD(){
    for(int i=0; i<n; i++)
      delete[] M[i];
    delete[] M;
  };

  int dp(int i, int j){
    if(M[i][j] != None)
      return M[i][j];

    if(!(i < j)){
      M[i][j] = 0;
      return M[i][j];
    }

    if(S[i] == S[j])
      M[i][j] = dp(i+1, j-1);
    else
      M[i][j] = 1 + min(dp(i+1, j), dp(i, j-1));
    return M[i][j];
  };

  int solve(){
    return dp(0, n-1);
  };
};

int main(){
  int t, n;
  string S;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d\n", &n);
    getline(cin, S);

    MD md(n, S);
    printf("%d\n", md.solve());
  }
  return 0;
}