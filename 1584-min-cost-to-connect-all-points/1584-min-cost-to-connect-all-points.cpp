using pii = pair<int, int>;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int cost = 0;
        vector<int> vis(n, 0);
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (vis[node]) {
                continue;
            }

            vis[node] = 1;
            cost += dis;

            for (auto [nbr, wt] : adj[node]) {
                if (!vis[nbr]) {
                    pq.push({wt, nbr});
                }
            }
        }

        return cost;
    }
};