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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);
        set<int> s;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int r1 = stones[i][0], r2 = stones[j][0];
                int c1 = stones[i][1], c2 = stones[j][1];

                if (r1 == r2 || c1 == c2) {
                    dsu.unite(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            s.insert(dsu.find(i));
        }

        return n - s.size();
    }
};