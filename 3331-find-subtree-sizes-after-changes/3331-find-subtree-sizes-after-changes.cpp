class Solution {
public:
    vector<int> res;
    vector<int> lastseen;
    vector<vector<int>> adj;
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        adj.resize(n);
        lastseen.assign(26, -1);
        res.assign(n, 1);

        for (int i = 1; i < parent.size(); i++) {
            int src = parent[i];
            adj[src].push_back(i);
        }

        solve(0, s, parent);
        return res;
    }

    void solve(int src, string& s, vector<int>& parent) {
        int c = s[src] - 'a';
        int near = lastseen[c];

        lastseen[c] = src;
        for (auto nbr : adj[src]) {
            solve(nbr, s, parent);
        }

        lastseen[c] = near;

        if (src != 0) {
            int newp = parent[src];
            if (near != -1) {
                newp = near;
            }

            res[newp] += res[src];
        }
    }
};