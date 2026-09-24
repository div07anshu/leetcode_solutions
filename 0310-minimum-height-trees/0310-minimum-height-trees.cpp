class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);
        if (n <= 2) {
            vector<int> result;
            for (int i = 0; i < n; i++) {
                result.push_back(i);
            }

            return result;
        }

        for (auto e : edges) {
            auto u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++, deg[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }

        int remm = n;

        while (remm > 2) {
            int leaf = q.size();
            remm -= q.size();

            for (int i = 0; i < leaf; i++) {
                auto node = q.front();
                q.pop();

                for (auto nbr : adj[node]) {
                    deg[nbr]--;

                    if (deg[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
        }

        vector<int> res;

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};