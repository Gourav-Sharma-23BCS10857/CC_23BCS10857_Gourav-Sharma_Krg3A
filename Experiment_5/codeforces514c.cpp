#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<string> dict;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.insert(s);
    }

    while(m--) {
        string query;
        cin >> query;

        bool found = false;

        for(int i = 0; i < query.length(); i++) {
            char original = query[i];

            for(char c : {'a', 'b', 'c'}) {
                if(c == original) continue;

                query[i] = c;

                if(dict.count(query)) {
                    found = true;
                    break;
                }
            }

            query[i] = original;

            if(found) break;
        }

        if(found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}