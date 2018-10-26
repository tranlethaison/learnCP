// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Get the min distance element's id that not yet in sptSet
int min_dist_id(const vector<int> dist, const bool sptSet[]){
    int min_id;
    int min_dist = INT_MAX;
    for(int i=0; i<dist.size(); i++){
        if(sptSet[i])
            continue;

        if(dist[i] < min_dist){
            min_dist = dist[i];
            min_id = i;
        }    
    }
    return min_id;
}

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    // Create distance graph, distance array, shortest path set 
    int graph[n][n];
    vector<int> dist(n);
    bool sptSet[n];
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
        for(int j=0; j<n; j++){
            graph[i][j] = 0;
        }
    }

    dist[s] = 0;
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0] - 1][edges[i][1] - 1] = edges[i][2];
    }

    // Graph
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    // Dijkstra Calculate distance
    int tar_id; // target node's id
    // Verticles loop
    for(int i=0; i<n; i++){
        //target node -> sptSet
        tar_id = min_dist_id(dist, sptSet);
        cout << tar_id;
        sptSet[tar_id] = true;

        // Update Adjacents' distance
        for(int j=0; j<n; j++){
            if(
                // dist[tar_id] != INT_MAX &&
                !sptSet[j] &&
                dist[tar_id] + graph[tar_id][j] < dist[j]
            )
                dist[j] = dist[tar_id] + graph[tar_id][j];
        }

        // for(int d=0; d<n; d++){
        //     cout << dist[d] << " ";
        // }
        // cout << "\n";
    }
    return dist;    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
