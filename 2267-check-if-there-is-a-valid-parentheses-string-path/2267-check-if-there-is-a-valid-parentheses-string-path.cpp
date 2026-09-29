class Solution {
public:
    int dp[105][105][205];

    bool solve(int i, int j, int bal, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (bal < 0)
            return false;

        if (i == m - 1 && j == n - 1) {
            return bal == 0;
        }

        if (dp[i][j][bal] != -1) {
            return dp[i][j][bal];
        }

        bool ans = false;

        if (i + 1 < m) {
            int nb = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            ans = ans | solve(i + 1, j, nb, grid);
        }

        if (j + 1 < n) {
            int nb = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            ans = ans | solve(i, j + 1, nb, grid);
        }

        return dp[i][j][bal] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        if ((m + n - 1) % 2)
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 1, grid);
    }
};