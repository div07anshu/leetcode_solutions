class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(
            n + 1, vector<unsigned long long>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }

    int solve(string& s, string& t, int i, int j) {

        if (i == 0 && j == 0) {
            if (s[i] == t[j]) {
                return 1;
            }
            return 0;
        }
        if (i < 0) {
            return 0;
        } else if (j < 0) {
            return 1;
        }

        if (s[i] == t[j]) {
            return solve(s, t, i - 1, j) + solve(s, t, i - 1, j - 1);
        } else {
            return solve(s, t, i - 1, j);
        }
    }
};