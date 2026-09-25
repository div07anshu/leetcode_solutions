class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int nodes = 1; nodes <= n; nodes++) {
            for (int i = 1; i <= nodes; i++) {
                dp[nodes] += dp[nodes - i] * dp[i - 1];
            }
        }

        return dp[n];
    }
};