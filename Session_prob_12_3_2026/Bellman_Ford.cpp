#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 0; i < V - 1; i++) {
        for(auto it : edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check negative cycle
    for(auto it : edges) {

        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected\n";
        }
    }

    return dist;
}

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,4,3},
        {3,4,1}
    };

    int src = 0;

    vector<int> result = bellmanFord(V, edges, src);

    for(int i = 0; i < V; i++) {
        cout << "Distance from " << src << " to " << i << " = " << result[i] << endl;
    }
}