#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<long long> tree, lazy;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * idx + 1, l, mid);
        build(arr, 2 * idx + 2, mid + 1, r);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            tree[idx] += (r - l + 1) * lazy[idx];
            if (l != r) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        push(idx, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * idx + 1, l, mid, ql, qr, val);
        update(2 * idx + 2, mid + 1, r, ql, qr, val);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        push(idx, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(2 * idx + 1, l, mid, ql, qr) +
               query(2 * idx + 2, mid + 1, r, ql, qr);
    }

    void rangeUpdate(int l, int r, int val) {
        update(0, 0, n - 1, l, r, val);
    }

    long long rangeQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    cout << st.rangeQuery(1, 4) << endl;
    st.rangeUpdate(1, 3, 5);
    cout << st.rangeQuery(1, 4) << endl;
    return 0;
}