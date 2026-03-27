 //we implented by union by size....
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
//(both size 1e3, 0)
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
        return parent[node] = findPar(parent[node]); // path compression
    }
    //we implented by union by size....


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
    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);

    if (dsu.findPar(3) == dsu.findPar(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    dsu.unionBySize(3, 7);

    if (dsu.findPar(3) == dsu.findPar(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    return 0;
}