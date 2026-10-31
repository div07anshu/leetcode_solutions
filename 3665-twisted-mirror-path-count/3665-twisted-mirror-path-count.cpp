class Solution {
public:
    const long long mod = 1e9 + 7;
    using ll = long long;
    int m, n;
    int dp[501][501][2];
    vector<vector<int>> grid;
    int uniquePaths(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        grid = g;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0);
    }

    ll dfs(int i, int j, int dir) {
        if (i >= m || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j][dir] != -1) {
            return dp[i][j][dir];
        }

        ll ans = 0;

        if (grid[i][j] == 1) {
            ans = (dir == 0) ? dfs(i + 1, j, 1) : dfs(i, j + 1, 0);
        } else {
            ans = (dfs(i, j + 1, 0) + dfs(i + 1, j, 1)) % mod;
        }

        return dp[i][j][dir] = ans;
    }
};