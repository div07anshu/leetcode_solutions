class Solution {
public:
    vector<int> childScore;
    vector<vector<int>> adj;
    vector<int> order;

    void dfs(int u) {
        for (auto v : adj[u]) {
            dfs(v);
        }
        order.push_back(u);
    }

    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        adj.resize(n);
        childScore.resize(n);

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                continue;
            }
            adj[parent[i]].push_back(i);
        }

        int x = solve(0, score);
        dfs(0);

        for (auto node : order) {
            int curr = score[node];
            int mins = INT_MAX;

            for (auto nbr : adj[node]) {
                curr += childScore[nbr];
                mins = min(mins, childScore[nbr]);
            }

            if (op[node] == 0 && mins < 0) {
                curr -= mins;
            } else if (op[node] == 1 && mins != INT_MAX) {
                curr -= mins;
            }

            childScore[node] = curr;
        }

        return childScore[0];
    }

    int solve(int src, vector<int>& score) {
        int curr = score[src];

        for (auto nbr : adj[src]) {
            curr += solve(nbr, score);
        }

        return childScore[src] = curr;
    }
};