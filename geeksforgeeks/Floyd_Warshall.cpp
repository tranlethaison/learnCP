#include <bits/stdc++.h>
using namespace std;

int T, V;

void floyd(vector<vector<int>>& dist){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> V;
        vector<vector<int>> graph(V, vector<int>(V));

        for(int w=0; w<V; w++){
            for(int h=0; h<V; h++){
                cin >> graph[w][h];
            }
        }

        floyd(graph);

        for(int w=0; w<V; w++){
            for(int h=0; h<V; h++){
                cout << graph[w][h] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
