class dsu {
public:
    vector<int> parent, rank;
    dsu(int n) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu ds(n);
        map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (!mapMailNode.count(mail)) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unite(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        vector<vector<string>> ans;

        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMail[node].push_back(mail);
        }

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) {
                continue;
            }

            vector<string> acc;
            acc.push_back(accounts[i][0]);

            for (auto& mail : mergedMail[i]) {
                acc.push_back(mail);
            }

            ans.push_back(acc);
        }

        return ans;
    }
};