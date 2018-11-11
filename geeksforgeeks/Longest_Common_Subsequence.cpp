//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0/?ref=self

#include <bits/stdc++.h>
using namespace std;

class Lcs{
  public:
    int n1, n2;
    string S1;
    string S2;

    Lcs(int n1, int n2);
    void read();
    int solve();
    void debug();
};

Lcs::Lcs(int n1, int n2){
  this->n1 = n1;
  this->n2 = n2;
};

void Lcs::read(){
  getline(cin, S1);
  getline(cin, S2);
};

int Lcs::solve(){
  int M[n1+1][n2+1];

  for(int i=0; i<n1+1; i++){
    for(int j=0; j<n2+1; j++){
      if(i == 0 || j == 0){
        M[i][j] = 0;
        continue;
      }

      if(S1[i-1] == S2[j-1])
        M[i][j] = M[i-1][j-1] + 1;
      else
        M[i][j] = max(
          M[i][j-1],
          M[i-1][j]
        );
    }
  }

  return M[n1][n2];
};

void Lcs::debug(){
  printf("%d %d\n", n1, n2);
  printf("%s\n", S1.c_str());
  printf("%s\n", S2.c_str());
};

int main(){
  int t, n1, n2;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d\n", &n1, &n2);
    Lcs lcs(n1, n2);
    lcs.read();
    // lcs.debug();
    printf("%d\n", lcs.solve());
  }
  return 0;
}