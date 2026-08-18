class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }

    int getSize(int x) { return size[find(x)]; }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            dsu.unite(u, v);
        }

        long long pairs = 0;

        for (int i = 0; i < n; i++) {
            pairs += n - dsu.getSize(i);
        }

        return pairs / 2;
    }
};