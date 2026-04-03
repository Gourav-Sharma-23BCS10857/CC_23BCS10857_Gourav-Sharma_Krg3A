#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    int n = nums.size();

    // Reduce array step by step
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            nums[j] = (nums[j] + nums[j + 1]) % 10;
        }
    }

    return nums[0];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << triangularSum(nums);

    return 0;
}