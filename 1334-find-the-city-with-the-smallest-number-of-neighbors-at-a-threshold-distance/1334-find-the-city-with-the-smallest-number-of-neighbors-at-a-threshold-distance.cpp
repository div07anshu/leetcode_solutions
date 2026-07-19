using pii = pair<int, int>;
using vpii = vector<pii>;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int ans = -1;
        int dis = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = dij(i, adj, th);

            if (cnt <= dis) {
                ans = i;
                dis = cnt;
            }
        }

        return ans;
    }

    int dij(int src, vector<vector<pair<int, int>>>& adj, int th) {
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        priority_queue<pii, vpii, greater<pii>> pq; // dis , node ;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dis[node]) {
                continue;
            }

            for (auto [nbr, wt] : adj[node]) {
                if (dis[node] + wt < dis[nbr]) {
                    dis[nbr] = dis[node] + wt;
                    pq.push({dis[nbr], nbr});
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (i != src && dis[i] <= th) {
                cnt++;
            }
        }

        return cnt;
    }
};