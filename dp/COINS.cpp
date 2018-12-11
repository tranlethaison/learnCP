// https://www.spoj.com/problems/COINS/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

map<uint, uint> M;

uint dp(uint i){
    if(M[i] != 0)
      return M[i];

    if(i <= 2)
      return M[i] = i;

    return M[i] = max(
        dp(i/2) + dp(i/3) + dp(i/4),
        i
    );
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  uint n;
  while(cin >> n){
    cout << dp(n) << "\n";
  }

  return 0;
}