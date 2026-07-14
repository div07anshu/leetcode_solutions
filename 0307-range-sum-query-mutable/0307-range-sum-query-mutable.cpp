class NumArray {
public:
    vector<int> arr;
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int st, int ed) {
        if (st == ed) {
            tree[node] = arr[st];
            return;
        }

        int mid = st + (ed - st) / 2;

        build(2 * node + 1, st, mid);
        build(2 * node + 2, mid + 1, ed);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void upd(int node, int st, int ed, int idx, int val) {
        if (st == ed) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        int mid = st + (ed - st) / 2;

        if (idx <= mid) {
            upd(2 * node + 1, st, mid, idx, val);
        } else {
            upd(2 * node + 2, mid + 1, ed, idx, val);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int st, int ed, int l, int r) {
        if (st > r || ed < l) {
            return 0; // no overlap;
        }

        if (l <= st && r >= ed) {
            return tree[node]; // complete overlap
        }

        int mid = st + (ed - st) / 2; // partial overlap

        int left = query(2 * node + 1, st, mid, l, r);
        int right = query(2 * node + 2, mid + 1, ed, l, r);

        return left + right;
    }

    void update(int idx, int val) { upd(0, 0, n - 1, idx, val); }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */