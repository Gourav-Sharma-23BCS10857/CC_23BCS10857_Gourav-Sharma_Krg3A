// We define a function f(x, y) as the number of different corresponding bits in the binary representations of the integers x and y.

// For example:

// f(2, 7) = 2


// because:

// 2 = 010
// 7 = 111


// and they differ in two bit positions.

// You are given an array A of n positive integers.
// Your task is to compute and return the sum of f(ai, aj) for all ordered pairs (i, j) such that i ≠ j.

#include <bits/stdc++.h>
using namespace std;

long long sumOfDifferentBits(vector<int>& A) {
    int n = A.size();
    long long total = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long count1 = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] & (1LL << bit))   
                count1++;
        }

        long long count0 = n - count1;
        total += count1 * count0;
    }

    return 2 * total;
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout << sumOfDifferentBits(A);
    return 0;
}
