class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;
    using vvvi = vector<vvi>;
    using vvvvi = vector<vvvi>;

    using state = tuple<int, int, int, int, int>;
    // cost , r , c , prev , turn ;
    // 0 - up , 1 - right , 2 - down , 3 - left;
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return grid[0][0];

        vvvvi cst(m, vvvi(n, vvi(5, vi(k + 1, INT_MAX))));
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({grid[0][0], 0, 0, 4, k});
        cst[0][0][4][k] = grid[0][0];

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [cost, r, c, prev, turn] = pq.top();
            pq.pop();

            if (cost != cst[r][c][prev][turn])
                continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newTurn = turn;

                if (prev != 4 && prev != i) {
                    newTurn--;
                }

                if (newTurn < 0) {
                    continue;
                }

                if (cst[nr][nc][i][newTurn] > cost + grid[nr][nc]) {
                    int newcost = cost + grid[nr][nc];
                    cst[nr][nc][i][newTurn] = newcost;
                    pq.push({newcost, nr, nc, i, newTurn});
                }
            }
        }

        int ans = INT_MAX;

        for (int dir = 0; dir < 4; dir++) {
            for (int turn = 0; turn <= k; turn++) {
                ans = min(ans, cst[m - 1][n - 1][dir][turn]);
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};