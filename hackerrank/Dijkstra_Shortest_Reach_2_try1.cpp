//https://www.hackerrank.com/challenges/dijkstrashortreach/problem
#include <bits/stdc++.h>
using namespace std;

int T;

void printPath(int pre[], int src, int dst){
  if(pre[dst] != -1 || dst == src){
    while(dst != -1){
      printf("%d ", dst);
      dst = pre[dst];
    }
  }
  printf("\n");
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d", &T);
  while(T--){
    int n, m, s;
    scanf("%d%d", &n, &m);

    vector<pair<int, int>> g[n];
    while(m--){
      int x, y, r;
      scanf("%d%d%d", &x, &y, &r);
      --x, --y;

      g[x].push_back({y, r});
      g[y].push_back({x, r});
    }

    scanf("%d", &s);
    --s;

    int dist[n];
    bool visited[n];
    int pre[n];
    for(int i=0; i<n; i++){
      dist[i] = INT_MAX;
      visited[i] = false;
      pre[i] = -1;
    }
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});

    while(!q.empty()){
      int src = q.top().second;
      int src_dist = q.top().first;
      q.pop();

      if(visited[src])
        continue;
      visited[src] = true;

      for(auto e : g[src]){
        int dst = e.first;
        int alt_dist = src_dist + e.second;

        if(dist[dst] > alt_dist){
          dist[dst] = alt_dist;
          pre[dst] = src;
          q.push({dist[dst], dst});
        }
      }
    }

    for(int i=0; i<n; i++){
      if(i == s)
        continue;
      printf("%d ", (dist[i] != INT_MAX) ? dist[i] : -1);
    }
    printf("\n");

    //for(int i=0; i<n; i++){
    //    printPath(pre, s, i);
    //}
  }

  return 0;
}
