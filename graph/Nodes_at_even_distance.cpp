#include <bits/stdc++.h>
using namespace std;

// stringstream cin_("1\n3\n1 2 2 3");

int n_cases;
int n_nodes;

class Graph{
  public:
    int mNodes;
    map<int, int> mDist;
    map< int, list<int> > mAdjs;

    Graph(int n_nodes){
      mNodes = n_nodes;
    };

    void add_edge(int v, int w){
      mAdjs[v].push_back(w);
    };

    void calc_dist(int root){
      queue<int> Q;
      Q.push(root);
      mDist[root] = 0;

      while(!Q.empty()){
        int front = Q.front();
        Q.pop();

        for(auto it=mAdjs[front].begin(); it!=mAdjs[front].end(); ++it){
          mDist[*it] = mDist[front] + 1;
          Q.push(*it);
        }
      }
    };

    int find_nodes(){
      int even = 0;
      int odd = 0;

      for(auto it=mDist.begin(); it!=mDist.end(); ++it){
        if(it->second % 2 == 0)
          even++;
        else
          odd++;
      }

      return (even*(even-1))/2 + (odd*(odd-1))/2;
    };
};

int main(){
  cin >> n_cases;
  for(int i=0; i<n_cases; i++){
    int v, w, root;
    cin >> n_nodes;

    Graph graph(n_nodes);
    for(int j=0; j<n_nodes-1; j++){
      cin >> v >> w;
      if(j==0)
        root = v;

      graph.add_edge(v, w);
    }
    graph.calc_dist(root);

    cout << graph.find_nodes() << endl;
  }
  return 0;
}
