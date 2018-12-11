#include <bits/stdc++.h>
using namespace std;

int n_tc, n, m;
vector<string> arr;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_outside(int x, int y) {
  return ((x<0) || (x>=n) || (y<0) || (y>=m));
}

bool floodfill(int x, int y){
  for(int i=0; i<4; i++){
    int kx = x + dx[i];
    int ky = y + dy[i];

    if(is_outside(kx, ky))
      continue;

    if(arr[kx][ky] == 'X'){
      arr[kx][ky] = 'O';
      floodfill(kx, ky);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n_tc;

  for(int i=0; i<n_tc; i++){
    cin >> n >> m;
    arr.resize(n);
    for(int x=0; x<n; x++){
      cin >> arr[x];
    }

    int n_islands = 0;
    for(int x=0; x<n; x++){
      for(int y=0; y<m; y++){
        if(arr[x][y] == 'X'){
          floodfill(x, y);
          n_islands++;
        }
      }
    }

    cout << n_islands << endl;
  }

  return 0;
}