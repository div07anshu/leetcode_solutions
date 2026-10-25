class Solution {
public:
    using vvi = vector<vector<int>>;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int n, m;

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (!dfs(i, j, grid, vis)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }

    bool dfs(int r, int c, vvi& grid, vvi& vis) {
        vis[r][c] = 1;
        bool touch = r == n - 1 || c == m - 1 || r == 0 || c == 0;
        bool cond = touch;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 &&
                !vis[nr][nc]) {
                cond |= dfs(nr, nc, grid, vis);
            }
        }

        return cond;
    }
};