//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
/*
X = { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

1. Subproblems
  - prefix :i

2. Guessing
  - f(i): lenght of LIS ending at i.

3. Recurrence
  - f(i) = max([
      f(j) + 1
      for j in range(i)
      if Xj < Xi
    ])
  - f(i) = 1, if no such j exists

4.    
*/
#include <bits/stdc++.h>
using namespace std;

class Lis{
  public:
    int n; // #elements
    int *X; // array
    int *M; // memory

    Lis(int n_elements);
    void read();
    int res(int i); // Recursion
    int solve(); // Solve original
};

Lis::Lis(int n_elements){
  n = n_elements;
  X = new int[n];
  M = new int[n];
  memset(M, -1, n * sizeof M[0]);
};

void Lis::read(){
  for(int i=0; i<n; i++)
    scanf("%d", &X[i]);
};

int Lis::res(int i){
  if(M[i] != -1) return M[i];

  int f = 1;
  for(int j=0; j<i; j++){
    if(X[j] < X[i])
      f = max(res(j) + 1, f);
  }

  M[i] = f;
  return f;
};

int Lis::solve(){  
  int f_max = 0;
  for(int i=0; i<n; i++)
    f_max = max(res(i), f_max);
  return f_max;
};

int main(){
  int t, n;

  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    Lis lis(n);
    lis.read();
    printf("%d\n", lis.solve());
  }

  return 0;
}