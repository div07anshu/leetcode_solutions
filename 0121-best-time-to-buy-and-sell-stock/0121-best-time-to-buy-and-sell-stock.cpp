class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        int minp = prices[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], prices[i] - minp);
            minp = min(minp, prices[i]);
        }

        return dp[n - 1];
    }
};