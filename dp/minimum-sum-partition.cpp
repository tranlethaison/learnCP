// https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include <bits/stdc++.h>
using namespace std;

class MinAbsSub{
public:
  int n;
  vector<int> A;
  unordered_map<string, int> M;

  MinAbsSub(int _n): n(_n){};

  void init(){
    A.reserve(n);
    for(int a=0; a<n; a++)
      scanf("%d", &A[a]);
  };

  int dp(int a, int s1, int s2){
    string key = to_string(a) + "|" + to_string(s1);

    if(M.find(key) != M.end())
      return M[key];

    if(a == 0)
      return abs(s1 - s2);

    M[key] = min(
      dp(a-1, s1 + A[a-1], s2),
      dp(a-1, s1, s2 + A[a-1])
    );
    return M[key];
  };

  int solve(){
    return dp(n, 0, 0);
  };
};

int main(){
  int t, n;
  scanf("%d\n", &t);
  while(t--){
    scanf("%d\n", &n);

    MinAbsSub mas(n);
    mas.init();

    printf("%d\n", mas.solve());
  }
  return 0;
}