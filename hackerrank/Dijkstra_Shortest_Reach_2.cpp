// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Get the min distance element's id that not yet in sptSet
int min_dist_id(const vector<int> dist, const bool sptSet[]){
    int min_id;
    int min_dist = INT_MAX;
    for(int i=0; i<dist.size(); i++){
        if( 
            !sptSet[i] &&
            dist[i] <= min_dist
        ){
            min_dist = dist[i];
            min_id = i;
        }
    }
    return min_id;
}

void print(map<int, vector<pair<int, int> > > eMap){
    for(auto e=eMap.begin(); e!=eMap.end(); ++e){
        cout << e->first << "| ";
        for(auto adj : e->second){
            cout << "(" << adj.first << ", " << adj.second << "), ";
        }
        cout << "\n";
    }
    cout << "--------------------\n";
}

// In case there are duplicated edges, remove all the larger 
void rm_duplicates(map<int, vector<pair<int, int> > > &eMap){
    for(auto e=eMap.begin(); e!=eMap.end(); ++e){
        // Sort adj by weight ASC
        sort(
            e->second.begin(), e->second.end(), 
            [](pair<int, int> &i, pair<int, int> &j){
                if(i.first < j.first) return true;
                else if(i.first > j.first) return false;

                if(i.second < j.second) return true;
                else if(i.second > j.second) return false;

                return false;
            }
        );

        vector<pair<int, int> > adjsTemp;
        int pre_dst = -1;
        for(auto adj : e->second){
            if(adj.first != pre_dst)
                adjsTemp.push_back(adj);
            pre_dst = adj.first;
        }
        eMap[e->first] = adjsTemp;
    }
}

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    // Create distance array, shortest path set
    vector<int> dist(n+1);
    bool sptSet[n+1];
    for(int i=0; i<n+1; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    // Edges map
    // eMap[src] = [(dst, w), ...]
    map<int, vector<pair<int, int> > > eMap;

    for(int i=0; i<edges.size(); i++){
        eMap[edges[i][0]].push_back(pair<int, int>(edges[i][1], edges[i][2]));
        eMap[edges[i][1]].push_back(pair<int, int>(edges[i][0], edges[i][2]));
    }
    // print(eMap);
    rm_duplicates(eMap);
    // print(eMap);

    // Dijkstra Calculate distance
    dist[s] = 0;
    int tar_id; // target node's id
    // Verticles loop
    for(int i=1; i<n+1; i++){
        //target node -> sptSet
        tar_id = min_dist_id(dist, sptSet);
        sptSet[tar_id] = true;

        // Update dist of adjacents
        for(auto adj : eMap[tar_id]){
            if(
                !sptSet[adj.first] && 
                dist[tar_id] != INT_MAX &&
                dist[tar_id] + adj.second < dist[adj.first]
            )
                dist[adj.first] = dist[tar_id] + adj.second;            
        }
    }

    vector<int> rv; //return array
    for(int i=1; i<n+1; i++){
        if(i == s)
            continue;

        if(dist[i] != INT_MAX)
            rv.push_back(dist[i]);
        else
            rv.push_back(-1);        
    }
    return rv;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
