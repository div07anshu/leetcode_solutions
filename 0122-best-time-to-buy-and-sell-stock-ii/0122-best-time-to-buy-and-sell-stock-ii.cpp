class Solution {
public:
    int profit = 0;
    int dp[30001][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }

    int solve(int i, int b, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][b] != -1) {
            return dp[i][b];
        }

        int skip = solve(i + 1, b, prices);

        if (b == 0) {
            int buy = -prices[i] + solve(i + 1, 1, prices);
            return dp[i][b] = max(buy, skip);
        } else {
            int sell = prices[i] + solve(i + 1, 0, prices);
            return dp[i][b] = max(sell, skip);
        }
    }
};