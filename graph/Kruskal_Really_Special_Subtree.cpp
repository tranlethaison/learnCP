//https://www.hackerrank.com/challenges/kruskalmstrsub/problem
#include <bits/stdc++.h>
using namespace std;

int n_nodes, n_edges;
struct edge{
  int fr;
  int to;
  int w;
};

struct subset{
  int parent;
  int rank_;
};

int find_(map<int, subset> &subsets, int x){
  if(subsets[x].parent != x)
    subsets[x].parent = find_(subsets, subsets[x].parent);
  return subsets[x].parent;
}

void union_(map<int, subset> &subsets, int x, int y){
  if(subsets[x].rank_ > subsets[y].rank_)
    subsets[y].parent = x;
  else if(subsets[x].rank_ < subsets[y].rank_)
    subsets[x].parent = y;
  else{
    subsets[y].parent = x;
    subsets[x].rank_++;
  }
}

int main(){
  scanf("%d%d", &n_nodes, &n_edges);

  edge edges[n_edges];
  for(int i=0; i<n_edges; i++){
    scanf("%d%d%d", &edges[i].fr, &edges[i].to, &edges[i].w);
  }

  map<int, subset> subsets;
  for(int i=1; i<=n_nodes; i++){
    subsets[i].parent = i;
    subsets[i].rank_ = 0;
  }

  sort(
    edges, edges + n_edges,
    [](edge &i, edge &j){ return i.w < j.w; }
  );

  int x, y;
  int MST_edges = 0;
  int MST_w = 0;
  for(auto e : edges){
    x = find_(subsets, e.fr);
    y = find_(subsets, e.to);

    if(x != y){
      union_(subsets, x, y);
      MST_w += e.w;
      MST_edges++;
      if(MST_edges == n_nodes - 1)
        break;
    }
  }

  printf("%d\n", MST_w);

  return 0;
}
