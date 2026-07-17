class Solution {
public:
    vector<int> getRow(int rowidx) {

        if (rowidx == 0) {
            return {1};
        }

        vector<vector<int>> dp(rowidx + 1, vector<int>(rowidx + 1));
        vector<int> ans;

        for (int i = 0; i <= rowidx; i++) {
            dp[i][0] = 1, dp[i][i] = 1;
        }

        for (int i = 2; i <= rowidx; i++) {
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        for (int k = 0; k <= rowidx; k++) {
            ans.push_back(dp[rowidx][k]);
        }

        return ans;
    }
};