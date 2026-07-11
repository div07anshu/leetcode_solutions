using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        int cnt = 0;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }

    bool bfs(int src, vvi& adj, vi& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        bool cond = true;
        int no = 1, ed = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    no++;
                    q.push(nbr);
                }
                ed++;
            }
        }

        int reqe = (no * (no - 1)) / 2;
        ed = ed / 2; // every edge is counted twice ;

        if (reqe == ed) {
            return true;
        }

        return false;
    }
};