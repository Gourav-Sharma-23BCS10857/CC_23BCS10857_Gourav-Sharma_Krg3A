#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {weight, node}

void prims(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> key(V, INT_MAX);   // Minimum weight to include node
    vector<bool> inMST(V, false);  // Track nodes in MST
    vector<int> parent(V, -1);     // Store MST

    key[0] = 0;
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Undirected Graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    prims(V, adj);

    return 0;
}
