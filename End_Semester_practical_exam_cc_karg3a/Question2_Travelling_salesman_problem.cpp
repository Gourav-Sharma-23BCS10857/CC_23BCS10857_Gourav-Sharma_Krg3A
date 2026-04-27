#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void build(vector<int>& arr, int idx, int low, int high) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(arr, 2*idx+1, low, mid);
    build(arr, 2*idx+2, mid+1, high);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int query(int idx, int low, int high, int l, int r) {
    if (r < low || high < l) return 0;
    if (l <= low && high <= r) return seg[idx];
    int mid = (low + high) / 2;
    return query(2*idx+1, low, mid, l, r) + query(2*idx+2, mid+1, high, l, r);
}

void update(int idx, int low, int high, int pos, int val) {
    if (low == high) {
        seg[idx] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid) update(2*idx+1, low, mid, pos, val);
    else update(2*idx+2, mid+1, high, pos, val);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int main() {
    int n = 6;
    vector<int> arr = {1,3,5,7,9,11};
    seg.resize(4*n);

    build(arr, 0, 0, n-1);

    cout << query(0, 0, n-1, 0, 2) << endl;

    update(0, 0, n-1, 3, 17);

    cout << query(0, 0, n-1, 0, 5) << endl;

    return 0;
}