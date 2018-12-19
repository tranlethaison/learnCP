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

string decode(int i){
  assert(i == 0 || i == 1);
  return i ? "YES" : "NO";
}

class SubsetSum{
public:
  int n, sumA, h;
  int *A, **M;
  int done; // keep track whether to stop dp.

  SubsetSum(int n_): n(n_){
    A = NULL;
    M = NULL;
    initA();
  };

  ~SubsetSum(){
    deleteA();
    deleteM();
  };

  int dp(int i, int h){
    if(done)
      return 1;

    if(h < 0)
      return 0;

    if(M[i][h] != None)
      return M[i][h];

    if(i == n-1)
      M[i][h] = (h == 0) ? 1 : 0;
    else
      M[i][h] = (dp(i+1, h-A[i]) || dp(i+1, h)) ? 1 : 0;

    done = M[i][h];

    return M[i][h];
  }

  int solve(){
    initM();
    done = 0;
    return dp(0, h);
  };

  void initA(){
    A = new int[n];
    sumA = 0;
    for(int i=0; i<n; i++){
      cin >> A[i];
      sumA += A[i];
    }
  };

  void deleteA(){
    if(A)
      delete[] A;
  };

  void initM(){
    h = sumA / 2;

    M = new int*[n];
    for(int i=0; i<n; i++){
      M[i] = new int[h+1];
      for(int j=0; j<h+1; j++)
        M[i][j] = None;
    }
  };

  void deleteM(){
    if(M){
      for(int i=0; i<n; i++)
        delete[] M[i];
      delete[] M;
    }
  };
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n;
  cin >> t;
  while(t--){
    cin >> n;
    SubsetSum ss(n);

    if(ss.sumA % 2 == 0)
      cout << decode(ss.solve()) << "\n";
    else
      cout << decode(0) << "\n";
  }
  return 0;
}