using vvi = vector<vector<int>>;
using vi = vector<int>;
using pii = pair<int, int>;
using pipi = pair<int, pii>;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mind(n, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pipi, vector<pipi>, greater<pipi>> pq;
        pq.push({1, {0, 0}});
        vis[0][0] = 1;

        int dr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
        int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

        if (grid[0][0] == 1) {
            return -1;
        } else {
            mind[0][0] = 1;
        }

        while (!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !grid[nr][nc] &&
                    !vis[nr][nc]) {

                    mind[nr][nc] = min(mind[nr][nc], dis + 1);
                    pq.push({mind[nr][nc], {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }

        if (mind[n - 1][n - 1] == INT_MAX) {
            return -1;
        }

        return mind[n - 1][n - 1];
    }
};