// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;

int t, n, c;

class Items{
  public:
    int n;
    int *V;
    int *W;
    Items(int n_Items);
    int max_value(int i, int X); //recure
    int max_value(int X); //bottom-up 
};

Items::Items(int n_Items){
  n = n_Items;
  V = new int[n];
  W = new int[n];
};

int Items::max_value(int i, int X){
  if(i == n || X == 0)
    return 0;

  if(W[i] > X)
    return max_value(i + 1, X); 
  else
    return max(
      max_value(i + 1, X),
      max_value(i + 1, X - W[i]) + V[i]
    );
};

int Items::max_value(int X){
  int M[n + 1][X + 1]; //memory

  for(int i=n; i>=0; i--){
    for(int r=0; r<=X; r++){
      if(i == n || r == 0)
        M[i][r] = 0;

      if(W[i] <= X)
        M[i][r] = max(
          M[i + 1][r],
          M[i + 1][r - W[i]] + V[i]
        );
      else
        M[i][r] = M[i + 1][r];
    }
  }

  return M[0][X];
};

int main(){
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    scanf("%d", &c);

    Items I(n);

    for(int i=0; i<n; i++){
      scanf("%d", &I.V[i]);
    }
    for(int i=0; i<n; i++){
      scanf("%d", &I.W[i]);
    }

    printf("%d\n", I.max_value(c));
  }

  return 0;
}