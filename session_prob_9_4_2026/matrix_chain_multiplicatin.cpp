#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int>& arr, int i, int j) {
    // Base case: single matrix
    if (i == j) return 0;

    int mini = INT_MAX;

    // Try all partitions
    for (int k = i; k < j; k++) {
        int cost = solve(arr, i, k)
                 + solve(arr, k+1, j)
                 + arr[i-1] * arr[k] * arr[j];  

        mini = min(mini, cost);
    }

    return mini;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();

    cout << "Minimum number of multiplications: "
         << solve(arr, 1, n-1);

    return 0;
}