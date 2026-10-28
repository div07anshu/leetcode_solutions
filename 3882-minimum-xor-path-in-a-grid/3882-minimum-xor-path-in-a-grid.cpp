class Solution {
public:
    int n, m;
    int ans = INT_MAX;

    vector<vector<vector<bool>>> dp;

    void solve(vector<vector<int>>& grid, int r, int c, int xr) {
        if (dp[r][c][xr]) {
            return;
        }

        dp[r][c][xr] = true;

        if (r == n - 1 && c == m - 1) {
            ans = min(ans, xr);
            return;
        }

        if (c + 1 < m) {
            solve(grid, r, c + 1, xr ^ grid[r][c + 1]);
        }

        if (r + 1 < n) {
            solve(grid, r + 1, c, xr ^ grid[r + 1][c]);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        ans = INT_MAX;

        dp.assign(n, vector<vector<bool>>(m, vector<bool>(1024, false)));

        solve(grid, 0, 0, grid[0][0]);

        return ans;
    }
};