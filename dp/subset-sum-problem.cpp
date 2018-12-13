// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
/*
1. Reducing:
  - Find if there is a subset with sum equal half sum of whole set.
  - If sum of whole set is odd -> return false 
  - Suffix A[i:]
  - Guess which is A[i] belongs to subset.
  - Recurrence: 
    dp(i, h) <-
      dp(i+1, h-A[i]) OR
      dp(i+1, h)

  - Base case:
    dp(n, h) <- if(h = 0)

  - O(n + h*n) = O(h*n) 
*/
#include <bits/stdc++.h>
using namespace std;

#define None -1

int t, n, sumA;
int *A, **M;

string decode(int b){
  assert(b == 0 || b == 1);
  return b ? "YES" : "NO";
}

int dp(int i, int h){
  if(h < 0)
    return 0;

  if(M[i][h] != None)
    return M[i][h];

  if(i == n)
    return M[i][h] = (h == 0) ? 1 : 0;

  return M[i][h] = (dp(i+1, h-A[i]) || dp(i+1, h)) ? 1 : 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> t;
  while(t--){
    cin >> n;
    A = new int[n];
    sumA = 0;
    for(int i=0; i<n; i++){
      cin >> A[i];
      sumA += A[i];
    }
    
    if(sumA % 2 == 0){
      int h = sumA / 2;

      M = new int*[n+1];
      for(int i=0; i<n+1; i++){
        M[i] = new int[h+1];
        for(int j=0; j<h+1; j++)
          M[i][j] = None;
      }

      cout << decode(dp(0, h)) << "\n";

      for(int i=0; i<n; i++)
        delete[] M[i];
      delete[] M;
    }
    else{
      cout << decode(0) << "\n";
    }

    delete[] A;
  }
  return 0;
}