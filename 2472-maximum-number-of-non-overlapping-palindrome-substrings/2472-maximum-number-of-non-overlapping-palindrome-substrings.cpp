class Solution {
public:
    int dp[2001][2001];
    vector<vector<bool>> ispallin;
    int maxPalindromes(string s, int k) {
        int n = s.size();
        ispallin.resize(n + 1, vector<bool>(n + 1, false));

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                int j = i + l - 1;

                if (i == j) {
                    ispallin[i][j] = true;
                } else if (i + 1 == j) {
                    ispallin[i][j] = (s[i] == s[j]);
                } else {
                    ispallin[i][j] = (s[i] == s[j]) && ispallin[i + 1][j - 1];
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(s, 0, k - 1, k);
    }

    int solve(string& s, int i, int j, int k) {

        if (i >= s.size() || j >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int take = 1 + solve(s, j + 1, j + k, k);
        int grow = solve(s, i, j + 1, k);
        int slide = solve(s, i + 1, j + 1, k);

        if (ispallin[i][j]) {
            return dp[i][j] = max({take, grow, slide});
        } else {
            return dp[i][j] = max(grow, slide);
        }
    }
};