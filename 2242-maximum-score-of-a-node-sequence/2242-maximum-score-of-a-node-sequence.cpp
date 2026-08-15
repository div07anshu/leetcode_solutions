class Solution {
public:
    int maximumScore(vector<int>& s, vector<vector<int>>& edges) {
        int n = s.size();
        vector<vector<int>> adj(n);
        int maxs = -1;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(),
                 [&](int a, int b) { return s[a] > s[b]; });

            if (adj[i].size() > 3) {
                adj[i].resize(3);
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];

            for (int a : adj[u]) {
                if (a == v)
                    continue;

                for (int b : adj[v]) {
                    if (b == u || b == a)
                        continue;

                    maxs = max(maxs, s[u] + s[v] + s[a] + s[b]);
                }
            }
        }
        return maxs;
    }
};