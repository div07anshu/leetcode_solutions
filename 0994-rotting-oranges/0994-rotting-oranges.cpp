using pi = pair<int, int>;
using pii = pair<int, pi>;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pii> q;
        int fresh = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int maxt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty()) {
            auto [time, cor] = q.front();
            auto [r, c] = cor;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    q.push({time + 1, {nr, nc}});
                    maxt = max(maxt, time + 1);
                    fresh--;
                }
            }
        }

        if (fresh == 0) {
            return maxt;
        }

        return -1;
    }
};