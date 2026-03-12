#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {

        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {

            int adjNode = it.first;
            int weight = it.second;

            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});

    adj[1].push_back({2,1});
    adj[1].push_back({3,7});

    adj[2].push_back({4,3});

    adj[3].push_back({4,1});

    int src = 0;

    vector<int> result = dijkstra(V, adj, src);

    for(int i = 0; i < V; i++) {
        cout << "Distance from " << src << " to " << i << " = " << result[i] << endl;
    }

}