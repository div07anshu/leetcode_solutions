class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        size[pu] += size[pv];
        parent[pv] = pu;
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    bool check(int u, int v) { return find(u) == find(v); }
};
class Solution {
public:
    bool equationsPossible(vector<string>& eq) {
        DSU dsu(26);

        for (int i = 0; i < eq.size(); i++) {
            int u = eq[i][0] - 'a', v = eq[i][3] - 'a';
            if (eq[i][1] == '=') {
                dsu.unite(u, v);
            }
        }

        for (int i = 0; i < eq.size(); i++) {
            int u = eq[i][0] - 'a', v = eq[i][3] - 'a';
            if (eq[i][1] == '!' && dsu.check(u, v)) {
                return false;
            }
        }

        return true;
    }
};