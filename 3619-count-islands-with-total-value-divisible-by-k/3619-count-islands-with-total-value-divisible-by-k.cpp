using vvi = vector<vector<int>>;

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int n, m;

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = dfs(i, j, grid, vis);

                    if (sum % k == 0) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }

    long long dfs(int r, int c, vvi& grid, vvi& vis) {
        vis[r][c] = 1;
        long long sum = grid[r][c];

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] > 0 &&
                !vis[nr][nc]) {
                sum += dfs(nr, nc, grid, vis);
            }
        }

        return sum;
    }
};