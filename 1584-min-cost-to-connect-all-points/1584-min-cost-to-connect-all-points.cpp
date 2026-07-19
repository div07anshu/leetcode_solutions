using pii = pair<int, int>;
using vpii = vector<pii>;
using gpii = greater<pii>;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<vpii> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pii, vpii, gpii> pq;
        vector<int> vis(n, 0);
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()) {
            auto [cst, node] = pq.top();
            pq.pop();

            if (vis[node]) {
                continue;
            }

            vis[node] = 1;
            sum += cst;

            for (auto [nbr, wt] : adj[node]) {
                if (!vis[nbr]) {
                    pq.push({wt, nbr});
                }
            }
        }

        return sum ;
    }
};