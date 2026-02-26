#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> res;
        long long cur = 0;
        vector<bool> used(n, false);

        for (int step = 0; step < n; step++) {
            int best = -1;
            long long best_val = cur;

            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    long long v = cur | a[i];
                    if (v > best_val) {
                        best_val = v;
                        best = i;
                    }
                }
            }

            if (best == -1) break;
            used[best] = true;
            cur |= a[best];
            res.push_back(a[best]);
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) res.push_back(a[i]);
        }

        for (auto x : res) cout << x << " ";
        cout << "\n";
    }

    return 0;
}