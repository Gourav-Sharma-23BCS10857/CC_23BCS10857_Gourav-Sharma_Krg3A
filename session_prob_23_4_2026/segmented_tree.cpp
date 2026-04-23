#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int>& arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2 * idx + 1, left, mid);
        build(arr, 2 * idx + 2, mid + 1, right);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int query(int idx, int left, int right, int ql, int qr) {
        if (qr < left || right < ql) return 0;
        if (ql <= left && right <= qr) return tree[idx];
        int mid = (left + right) / 2;
        return query(2 * idx + 1, left, mid, ql, qr) +
               query(2 * idx + 2, mid + 1, right, ql, qr);
    }

    void update(int idx, int left, int right, int pos, int val) {
        if (left == right) {
            tree[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid)
            update(2 * idx + 1, left, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, right, pos, val);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int rangeQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void pointUpdate(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    cout << st.rangeQuery(1, 4) << endl;
    st.pointUpdate(2, 10);
    cout << st.rangeQuery(1, 4) << endl;
    return 0;
}