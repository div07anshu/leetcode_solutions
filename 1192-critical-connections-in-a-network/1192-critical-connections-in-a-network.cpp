using vvi = vector<vector<int>>;
using vi = vector<int>;

vector<int> tin;
vector<int> low;
vector<vector<int>> res;
int timer;

void dfs(int src, int p, vi& vis, vvi& adj, vvi& res) {
    vis[src] = 1;
    low[src] = tin[src] = timer;
    timer++;

    for (auto nbr : adj[src]) {
        if (nbr == p)
            continue;

        if (!vis[nbr]) {
            dfs(nbr, src, vis, adj, res);
            low[src] = min(low[src], low[nbr]);

            if (low[nbr] > tin[src]) {
                res.push_back({nbr, src});
            }

        } else {
            low[src] = min(low[src], low[nbr]);
        }
    }
}
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vvi& edge) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i][0], v = edge[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        low.resize(n);
        vector<vector<int>> res;
        tin.resize(n);
        timer = 0;
        dfs(0, -1, vis, adj, res);

        return res;
    }
};