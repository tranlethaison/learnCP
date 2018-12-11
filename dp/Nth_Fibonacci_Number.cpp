// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int uBigInt;

int T, n;

class Fibo{
  public:
    map<int, uBigInt> mMemo;
    uBigInt re(int n); // recurse + memorize
    uBigInt bu(int n); // bottom up
};

uBigInt Fibo::re(int n){
  if(mMemo.find(n) != mMemo.end())
    return mMemo[n];

  uBigInt f;
  if(n == 0)
    f = 0;
  else if(n == 1)
    f = 1;
  else
    f = (re(n - 1) + re(n - 2)) % 1000000007;

  mMemo[n] = f;
  return f;
};

uBigInt Fibo::bu(int n){
  uBigInt memo[n + 1];

  for(int k=0; k<=n; k++){
    if(k == 0)
      memo[k] = 0;
    else if(k == 1)
      memo[k] = 1;
    else
      memo[k] = (memo[k - 1] + memo[k - 2]) % 1000000007;
  }

  return memo[n];
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);

    Fibo fibo;
    // printf("%u\n", fibo.re(n));
    printf("%u\n", fibo.bu(n));
  }
  return 0;
}