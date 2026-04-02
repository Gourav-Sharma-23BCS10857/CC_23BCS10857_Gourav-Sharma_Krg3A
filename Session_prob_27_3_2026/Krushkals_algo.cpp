// the given graph contains  6 edges 1,2,3,4,5,6
// the edges are 5-4(9) ,5-1(4), 1-4(1),1-2(2) ,4-2(3),4-3(5),3-6(8),2-6(7),3-2(3)
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    int n = 6;
vector<int>v={1,2,3,4,5,5,56,6,5,4534,43534,34,,43,43};
    vector<pair<int, pair<int,int>>> edges = {
        {9, {5,4}},
        {4, {5,1}},
        {1, {1,4}},
        {2, {1,2}},
        {3, {4,2}},
        {5, {4,3}},
        {8, {3,6}},
        {7, {2,6}},
        {3, {3,2}}
    };

    // Step 1: sort edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);

    int mstWeight = 0;
    vector<pair<int,int>> mstEdges;

    // Step 2: iterate edges
    for (auto &it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // Step 3: check if already connected
        if (dsu.findPar(u) != dsu.findPar(v)) {
            mstWeight += wt;
            mstEdges.push_back({u, v});
            dsu.unionBySize(u, v);
        }
    }

    // Output
    cout << "MST Weight: " << mstWeight << endl;
    cout << "Edges in MST:\n";

    for (auto &e : mstEdges) {
        cout << e.first << " - " << e.second << endl;
    }

    return 0;
}
