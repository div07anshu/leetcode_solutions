using vi = vector<int>;
class Solution {
public:
    int dp[100001][2][3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, prices, 0, 2);
    }

    int solve(int i, vi& prices, int b, int k) {
        if (i >= prices.size() || k <= 0) {
            return 0;
        }

        if (dp[i][b][k] != -1) {
            return dp[i][b][k];
        }

        int skip = solve(i + 1, prices, b, k);
        if (b == 0) {
            int buy = -prices[i] + solve(i + 1, prices, 1, k);
            return dp[i][b][k] = max(buy, skip);
        } else {
            int sell = prices[i] + solve(i + 1, prices, 0, k - 1);
            return dp[i][b][k] = max(sell, skip);
        }
    }
};