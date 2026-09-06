class Solution {
public:
    int n, m;
    int dp[2001][2001];
    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }

    bool solve(int i, int j, string& s, string& p) {
        if (i == n && j == m) {
            return true;
        } else if (j == m) {
            return false;
        }

        if (i == n) {
            for (int k = j; k < m; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }

            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        } else if (p[j] == '*') {
            return dp[i][j] = solve(i, j + 1, s, p) || solve(i + 1, j, s, p);
        } else {
            return dp[i][j] = false;
        }
    }
};