// https://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include <bits/stdc++.h>
using namespace std;

class PIM{
  public:
    int n;
    int** M; // Matrix

    void Init(){
      M = new int*[n];
      for(int i=0; i<n; i++){
        M[i] = new int[n];
        for(int j=0; j<n; j++){
          scanf("%d", &M[i][j]);
        }
      }
    };

    int solve(){
    };
};

int t;

int main(){
  scanf("%d\n", &t);
  while(t--){
    PIM pim;
    scanf("%d\n", &pim.n);
    pim.Init();

  }

  return 0;
}