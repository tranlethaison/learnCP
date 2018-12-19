// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
/*
A: [a_0, a_1 ... a_n-1]

- Subproblems: suffix A[i:]

- Guess: at A[i], how many steps should we take?

- Recurrence:
  Let dp(i) return the number of jumps to reach the end of array.

  dp(i) = 1 + min([
    dp(i+j)
    for j in range(1, A[i]+1)
    if i+j < n
  ])

- Topo:
  # Special case:
  if A[0] == 0:
    if n == 1:
      return 0
    if n > 1:
      return -1

  # Base case:
  if i == n-1
    T[i] = 0

  for i in range(n-2, 0, -1):
    # Recurrence
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int *A){
  if(A[0] == 0)
    if(n == 1)
      return 0;
    else if(n > 1)
      return -1;
  
  int T[n];
  T[n-1] = 0;
  
  for(int i=n-2; i>=0; i--){
    if(A[i] == 0)
      T[i] = -1;
    else{
      T[i] = INT_MAX;
      for(int j=1; j<=A[i]; j++)
        if((i+j < n) && (T[i+j] != -1))
          T[i] = min(T[i+j], T[i]);

      if(T[i] != INT_MAX)
        T[i]++;
      else
        T[i] = -1;
    }
  }

  return T[0];
}

int main(){
  int t, n, *A;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d\n", &n);

    A = new int[n];
    for(int i=0; i<n; i++)
      scanf("%d", &A[i]);

    printf("%d\n", solve(n, A));

    delete[] A;
  }
  
  return 0;
}