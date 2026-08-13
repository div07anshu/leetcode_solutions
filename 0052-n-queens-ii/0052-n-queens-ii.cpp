using vvc = vector<vector<char>>;
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '#'));
        int cnt = 0;
        solve(0, board, cnt, n);
        return cnt;
    }

    void solve(int c, vvc& board, int& cnt, int n) {
        if (c == n) {
            cnt++;
            return;
        }

        for (int r = 0; r < n; r++) {
            if (isSafe(r, c, board, n)) {
                board[r][c] = 'Q';
                solve(c + 1, board, cnt, n);
                board[r][c] = '#';
            }
        }
    }

    bool isSafe(int row, int col, vvc& board, int n) {

        // upper_left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--, c--;
        }

        // bottom_left diagonal
        r = row, c = col;

        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r++, c--;
        }

        // backward
        r = row, c = col;

        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }

        return true;
    }
};