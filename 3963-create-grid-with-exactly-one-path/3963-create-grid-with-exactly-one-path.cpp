class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string> grid(m, string(n, '#'));

        for (int j = 0; j < m; j++) {
            grid[j][0] = '.';
        }

        for (int i = 0; i < n; i++) {
            grid[m - 1][i] = '.';
        }

        return grid;
    }
};