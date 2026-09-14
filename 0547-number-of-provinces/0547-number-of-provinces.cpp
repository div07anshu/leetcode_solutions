class DSU {
public:
    vector<int> parent, size;
    int cnt;

    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);
        cnt = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) {
            return;
        }

        if (size[pa] < size[pb]) {
            swap(pa, pb);
        }

        size[pa] += size[pb];
        cnt--;
        parent[pb] = pa;
    }

    int find(int a) {
        if (parent[a] == a) {
            return a;
        }

        return parent[a] = find(parent[a]);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1) {
                    dsu.unite(i, j);
                }
            }
        }

        return dsu.cnt;
    }
};