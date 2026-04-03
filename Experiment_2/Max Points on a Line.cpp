#include <bits/stdc++.h>
using namespace std;

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> mp;
        int duplicates = 1; // count current point itself
        int currMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            // Case: duplicate point
            if (dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }

            // Reduce slope
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Store as string to avoid pair hashing issue
            string slope = to_string(dy) + "/" + to_string(dx);

            mp[slope]++;
            currMax = max(currMax, mp[slope]);
        }

        // Add duplicates
        result = max(result, currMax + duplicates);
    }

    return result;
}

int main() {
    vector<vector<int>> points = {{1,1},{2,2},{3,3},{4,5}};
    cout << maxPoints(points) << endl;
    return 0;
}