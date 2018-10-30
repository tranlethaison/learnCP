// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;

int t, n, c;

class items{
  public:
    int n;
    int *V;
    int *W;
    items(int n_items);
    int max_value(int i, int X);
};

items::items(int n_items){
  n = n_items;
  V = new int[n];
  W = new int[n];
};

int items::max_value(int i, int X){
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

int main(){
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    scanf("%d", &c);

    items I(n);

    for(int i=0; i<n; i++){
      scanf("%d", &I.V[i]);
    }
    for(int i=0; i<n; i++){
      scanf("%d", &I.W[i]);
    }

    printf("%d\n", I.max_value(0, c));
  }

  return 0;
}