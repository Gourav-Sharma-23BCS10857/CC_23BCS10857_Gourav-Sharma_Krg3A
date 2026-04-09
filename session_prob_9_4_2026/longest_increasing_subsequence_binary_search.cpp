#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& arr) {
    vector<int> temp;

    for (int x : arr) {
        auto it = lower_bound(temp.begin(), temp.end(), x);

        if (it == temp.end()) {
            temp.push_back(x);
        } else {
            *it = x;
        }
    }

    return temp.size();
}

int main() {
    vector<int> arr = {1, 3, 7, 2, 5};

    cout << "Length of LIS: " << lengthOfLIS(arr);

    return 0;
}