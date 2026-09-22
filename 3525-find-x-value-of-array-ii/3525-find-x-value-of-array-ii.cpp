using vi = vector<int>;
using vvi = vector<vector<int>>;

struct Node {
    int count[5] = {0};
    int prod = 1;
};

class segTree {
public:
    int n, k;
    vector<Node> segtree;

    segTree(vi& nums, int k) {
        this->n = nums.size();
        this->k = k;

        segtree.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    Node mergeNodes(Node& a, Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;
        for (int x = 0; x < k; x++) {
            res.count[x] = a.count[x];
        }

        for (int r = 0; r < k; r++) {
            res.count[(a.prod * r) % k] += b.count[r];
        }

        return res;
    }

    void build(int i, int l, int r, vi& nums) {
        if (l == r) {
            leafNode(i, nums[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);

        segtree[i] = mergeNodes(segtree[2 * i + 1], segtree[2 * i + 2]);
    }

    void leafNode(int i, int val) {
        for (int x = 0; x < k; x++) {
            segtree[i].count[x] = 0;
        }

        int r = val % k;
        segtree[i].count[r] = 1;
        segtree[i].prod = r;
    }

    void segupd(int i, int l, int r, int idx, int val) {
        if (l == r) {
            leafNode(i, val);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            segupd(2 * i + 1, l, mid, idx, val);
        } else {
            segupd(2 * i + 2, mid + 1, r, idx, val);
        }

        segtree[i] = mergeNodes(segtree[2 * i + 1], segtree[2 * i + 2]);
    }

    Node query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return segtree[i];
        }

        if (r < ql || l > qr) {
            return Node();
        }

        int mid = l + (r - l) / 2;
        Node left = query(2 * i + 1, l, mid, ql, qr);
        Node right = query(2 * i + 2, mid + 1, r, ql, qr);
        return mergeNodes(left, right);
    }

    void update(int idx, int val) { segupd(0, 0, n - 1, idx, val); }
    Node query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vvi& queries) {
        int n = nums.size();

        segTree st(nums, k);
        vector<int> result;

        for (auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int s = q[2];
            int x = q[3];

            st.update(idx, val);
            Node resultNode = st.query(s, n - 1);
            result.push_back(resultNode.count[x]);
        }

        return result;
    }
};