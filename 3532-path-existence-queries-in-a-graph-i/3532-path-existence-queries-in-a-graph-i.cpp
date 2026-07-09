using vvi = vector<vector<int>>;
using vi = vector<int>;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vi& nums, int md, vvi& q) {
        vector<bool> ans(q.size());
        DSU dsu(n);

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= md) {
                dsu.unite(i, i - 1);
            }
        }

        for (int i = 0; i < q.size(); i++) {
            int u = q[i][0], v = q[i][1];

            if (dsu.find(u) == dsu.find(v)) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }

        return ans;
    }
};