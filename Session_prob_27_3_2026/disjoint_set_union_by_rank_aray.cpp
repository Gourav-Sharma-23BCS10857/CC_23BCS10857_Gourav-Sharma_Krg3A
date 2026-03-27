#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } 
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } 
        else {
            parent[pv] = pu;
            rank[pu]++; // increase rank when equal
        }
    }
};

int main() {
    DSU dsu(7);

    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(6, 7);
    dsu.unionByRank(5, 6);

    if (dsu.findPar(3) == dsu.findPar(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    dsu.unionByRank(3, 7);

    if (dsu.findPar(3) == dsu.findPar(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    return 0;
}