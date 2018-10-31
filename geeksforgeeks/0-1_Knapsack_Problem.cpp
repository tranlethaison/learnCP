// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;

int t, n, c;

class Knapsack{
  public:
    int n; // #items
    int C; // Capacity
    int *V; // Values
    int *W; // Weights
    int **M; // Memory
    // map<pair<int, int>, int> M; // Memory

    void init_items(int n_items);
    void init_memory(int capacity);
    Knapsack(int n_items, int capacity);
    Knapsack(int n_items);
    
    int res(int i, int X); // recure + memorize
    int bup(int X); // bottom up
};

void Knapsack::init_items(int n_items){
  n = n_items;
  V = new int[n];
  W = new int[n];
};

void Knapsack::init_memory(int capacity){
  C = capacity;
  M = new int*[n + 1];
  for(int i=0; i<=n; i++){
    M[i] = new int[C + 1];
    for(int j=0; j<=C; j++){
      M[i][j] = -1;
    }
  }
};

Knapsack::Knapsack(int n_items, int capacity){
  init_items(n_items);
  init_memory(capacity);
};

Knapsack::Knapsack(int n_items){
  init_items(n_items);
};

// Params:
//  i: begin of suffix from item i-th [i:]
//  X: remaining capacity
// Returns: 
//  Maximum value of knapsack with capacity X, given items V[i:], W[i:].  
int Knapsack::res(int i, int X){
  if(M[i][X] != -1)
   return M[i][X];
  // if(M.find({i, X}) != M.end())
  //   return M[{i, X}];

  int f;
  if(i == n || X == 0)
    f = 0;
  else if(W[i] > X)
    f = res(i + 1, X);
  else
    f = max(
      res(i + 1, X),
      res(i + 1, X - W[i]) + V[i]
    );

  M[i][X] = f;
  // M[{i, X}] = f;
  return f;
};

int Knapsack::bup(int X){
  int M[n + 1][X + 1];

  for(int i=n; i>=0; i--){
    for(int r=0; r<=X; r++){
      if(i == n || r == 0)
        M[i][r] = 0;
      else if(W[i] > r)
        M[i][r] = M[i + 1][r];
      else
        M[i][r] = max(
          M[i + 1][r],
          M[i + 1][r - W[i]] + V[i]
        );
    }
  }

  return M[0][X];
};

int main(){
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    scanf("%d", &c);

    // Knapsack K(n, c);
    Knapsack K(n);

    for(int i=0; i<n; i++){
      scanf("%d", &K.V[i]);
    }
    for(int i=0; i<n; i++){
      scanf("%d", &K.W[i]);
    }

    // printf("%d\n", K.res(0, c));
    printf("%d\n", K.bup(c));
  }

  return 0;
}