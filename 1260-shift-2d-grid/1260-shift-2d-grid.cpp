class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        k %= (n * m);

        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < m * n; i++) {
            int r = i / m;
            int c = i % m;
            int nr, nc;

            if (i + k >= m * n) {
                nr = (i + k - (m * n)) / m;
            } else {
                nr = (i + k) / m;
            }

            if (i + k >= m * n) {
                nc = (i + k - (m * n)) % m;
            } else {
                nc = (i + k) % m;
            }

            mat[nr][nc] = grid[r][c];
        }

        return mat;
    }
};