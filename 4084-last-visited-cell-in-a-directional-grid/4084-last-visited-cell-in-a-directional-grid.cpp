class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> ans = {0, 0};
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            char dir = grid[r][c];
            int nr = r, nc = c;

            if (dir == 'D') {
                nr += 1;
            } else if (dir == 'L') {
                nc -= 1;
            } else if (dir == 'R') {
                nc += 1;
            } else {
                nr -= 1;
            }

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == -1) {
                q.push({nr, nc});
                ans = {nr, nc};
                vis[nr][nc] = 1;
            }
        }

        return {ans.first, ans.second};
    }
};