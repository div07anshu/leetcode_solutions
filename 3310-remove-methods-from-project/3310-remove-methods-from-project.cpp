using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edge) {
        vector<vector<int>> adj(n);
        for (auto& e : edge) {
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(n, 0);
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        vector<int> m(n, 0);
        vector<int> sol;

        dfs(k, adj, vis, m);

        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i][0], v = edge[i][1];

            if (!m[u] && m[v]) {
                return arr;
            }
        }

        for (int i = 0; i < n; i++) {
            if (m[i] == 0) {
                sol.push_back(i);
            }
        }

        return sol;
    }

    void dfs(int src, vvi& adj, vi& vis, vi& m) {
        vis[src] = 1;
        m[src] = 1;

        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, m);
            }
        }
    }
};