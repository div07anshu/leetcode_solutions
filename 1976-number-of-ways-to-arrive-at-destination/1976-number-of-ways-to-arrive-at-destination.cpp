using vi = vector<int>;
using vvi = vector<vector<int>>;
using pll = pair<long long, long long>;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        int cnt = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0], v = roads[i][1], t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<int> ways(n, 0);
        ways[0] = 1;
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto p = pq.top();
            auto ini = p.first;
            auto node = p.second;
            pq.pop();

            if (ini > dis[node]) {
                continue;
            }

            for (auto [nbr, d] : adj[node]) {

                if (dis[nbr] > dis[node] + d) {
                    dis[nbr] = dis[node] + d;
                    pq.push({dis[nbr], nbr});
                    ways[nbr] = ways[node];
                } else if (dis[nbr] == dis[node] + d) {
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};