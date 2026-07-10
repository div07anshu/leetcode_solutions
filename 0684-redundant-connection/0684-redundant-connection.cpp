
class DSU {
public:
    vector<int> parent, rank;
    vector<int> ans;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        ans.resize(2, 0);

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

        if (pu == pv) {
            ans[0] = u, ans[1] = v;
            return;
        }
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);

        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            dsu.unite(u, v);
        }

        return dsu.ans;
    }
};