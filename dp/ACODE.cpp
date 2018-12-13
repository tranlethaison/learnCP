// https://www.spoj.com/problems/ACODE/
/*
- Subproblem: suffix C[:i]
- Guess: is C[i] stand with C[i-1] or not?
- Recurrence:
  dp(i) =
    dp(i-1) + // if C[i-1] is a valid code
    dp(i-2) // if C[i-2:i] is a valid code
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_valid(string s){
  int num = stoi(s);
  return (s[0] != '0') && (1 <= num) && (num <= 26);
}

ll solve(string C){
  ll alone, couple;

  int n = C.size();
  ll T[n+1];

  T[0] = 1;
  for(int i=1; i<=n; i++){
    alone = ((i-1 >= 0) && is_valid(C.substr(i-1, 1))) ? T[i-1] : 0;
    couple = ((i-2 >= 0) && is_valid(C.substr(i-2, 2))) ? T[i-2] : 0;
    T[i] = alone + couple;
  }

  return T[n];
};

int main(){
  string C;
  while(getline(cin, C)){
    if(C[0] != '0')
      printf("%lli", solve(C));
    printf("\n");
  }
  return 0;
}