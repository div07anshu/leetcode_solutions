using vi = vector<int>;
class Solution {
public:
    int dp[1001][2][101];
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, prices);
    }

    int solve(int i, int b, int k, vi& prices) {
        if (i >= prices.size() || k <= 0) {
            return 0;
        }

        if (dp[i][b][k] != -1) {
            return dp[i][b][k];
        }

        int skip = solve(i + 1, b, k, prices);

        if (b == 0) {
            int buy = -prices[i] + solve(i + 1, 1, k, prices);
            return dp[i][b][k] = max(skip, buy);
        } else {
            int sell = prices[i] + solve(i + 1, 0, k - 1, prices);
            return dp[i][b][k] = max(skip, sell);
        }
    }
};