// https://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include <bits/stdc++.h>
using namespace std;

class PIM{
  public:
    int n;
    int** M; // Matrix

    void init(){
      M = new int*[n];
      for(int i=0; i<n; i++){
        M[i] = new int[n];
        for(int j=0; j<n; j++){
          scanf("%d", &M[i][j]);
          // printf("%d ", M[i][j]);
        }
        // printf("\n");
      }
      // printf("\n");
    };

    /*
    Calculate max len path to every cell[n-1][j], then take max of them.
    */
    int solve(){
      int D[n][n]; // Distance matrix

      // Topological
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(i == 0){
            D[i][j] = M[i][j];
          }
          else if(j == 0){
            D[i][j] = max({
              M[i][j] + D[i-1][j],
              M[i][j] + D[i-1][j+1]
            });
          }
          else if(j == n-1){
            D[i][j] = max({
              M[i][j] + D[i-1][j],
              M[i][j] + D[i-1][j-1]
            });
          }
          else{
            D[i][j] = max({
              M[i][j] + D[i-1][j],
              M[i][j] + D[i-1][j-1],
              M[i][j] + D[i-1][j+1]
            }); 
          }
          // printf("%d ", D[i][j]);
        }
        // printf("\n");
      }
      // printf("\n");
      
      // Solve original problems
      int max_path_len = 0;
      for(int j=0; j<n; j++)
        max_path_len = max(D[n-1][j], max_path_len);
      return max_path_len;
    };
};

int t;

int main(){
  scanf("%d\n", &t);
  while(t--){
    PIM pim;
    scanf("%d\n", &pim.n);
    pim.init();
    printf("%d\n", pim.solve()); 
  }
  return 0;
}