// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int>& arr, int prev, int curr) {
//     vector<vector<int>>dp()
//     if (curr == arr.size()) return 0;

//     int notTake = solve(arr, prev, curr + 1);

//     int take = 0;
//     if (prev == -1 || arr[curr] > arr[prev]) {
//         take = 1 + solve(arr, curr, curr + 1);
//     }

//     return max(take, notTake);
// }

// int main() {
//     vector<int> arr = {1, 3, 7, 2, 5};

//     cout << "Length of LIS: " << solve(arr, -1, 0);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int prev, int curr, vector<vector<int>>& dp) {
  
    if (curr == arr.size()) return 0;

    if (dp[curr][prev + 1] != -1) 
        return dp[curr][prev + 1];

    int notTake = solve(arr, prev, curr + 1, dp);

  
    int take = 0;
    if (prev == -1 || arr[curr] > arr[prev]) {
        take = 1 + solve(arr, curr, curr + 1, dp);
    }

    return dp[curr][prev + 1] = max(take, notTake);
}

int main() {
    vector<int> arr = {1, 3, 7, 2, 5};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << "Length of LIS: " << solve(arr, -1, 0, dp);

    return 0;
}