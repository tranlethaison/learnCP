// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int spanningTree(vector <pair<int,int> > g[], int n);
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
	vector <pair<int,int> > adj[MAX];
    int n,e;
    int w, mC;
    cin >> n>> e;
    for(int i = 0;i < e;++i)
    {
    	int x,y;
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }

    mC = spanningTree(adj, MAX);
    cout << mC << endl;
	}
    return 0;
}

// Union-find
struct subset{
    int parent, rank;
};  

ostream& operator<<(ostream &out, const subset &s){
    out << s.parent << ", " << s.rank;
    return out;
}

int find(map<int, subset> &subsets, int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void union_(map<int, subset> &subsets, int x, int y){
    if(subsets[x].rank < subsets[y].rank)
        subsets[x].parent = y;
    else if(subsets[y].rank < subsets[x].rank)
        subsets[y].parent = x;
    else{
        subsets[y].parent = x;
        subsets[x].rank++;
    }
}
// [END] Union-find

struct edge{
    int src, dst, w;
};

ostream& operator<<(ostream &out, const edge &e){
    out << e.src << ", " << e.dst << ", " << e.w;
    return out;
}

bool cmp_edge(edge e0, edge e1){
    return (e0.w < e1.w);
}

/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
    Graph is represented as adjacency list using array of vectors.  MAX
    is an upper  limit on number of vertices.
   g[u] represents adjacency list of vertex u,  Every element of this list
   is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
  Note : Vertex numbers start with 1 and don't need to be contiguous.   */
int spanningTree(vector<pair<int,int> > g[], int MAX)
{
	// read g[] -> array of edges
    // create subset for each verticle
    int n_verticles = 0;
    subset subTemp;
    map<int, subset> subsets;
    edge eTemp;
    vector<edge> edges;

    for(int i=1; i<MAX; i++){
        if(g[i].size() < 1)
            continue;

        subTemp.parent = i;
        subTemp.rank = 0;
        subsets[i] = subTemp;
        n_verticles++;

        for(auto p : g[i]){
            eTemp.src = i;
            eTemp.dst = p.second;
            eTemp.w = p.first;

            edges.push_back(eTemp);
        }
    }
    // sort ASC by edges weight
    sort(edges.begin(), edges.end(), cmp_edge);
    // for(auto e : edges){
    //     cout << e << "\n";
    // }

    // edge MST[n_verticles - 1];

    // Loop edges
    // - Add smallest weight edges to MST,
    //  if it's not form circle with edges in MST
    int n_MST_edges = 0;
    int weights = 0;
    int x, y;
    for(auto edge : edges){
        x = find(subsets, edge.src);
        y = find(subsets, edge.dst);
        if(x != y){
            union_(subsets, x, y);
            
            // MST[n_MST_edges] = edge;
            weights += edge.w;
            n_MST_edges++;
            if(n_MST_edges == (n_verticles - 1))
                break;
        }
    }

    // Calculate sum of MST weights
    return weights;
}