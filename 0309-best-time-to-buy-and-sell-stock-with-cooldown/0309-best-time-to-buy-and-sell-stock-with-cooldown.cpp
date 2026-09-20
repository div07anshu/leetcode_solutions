using vi = vector<int>;
class Solution {
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }

    int solve(int i, int b, vi& prices) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][b] != -1) {
            return dp[i][b];
        }

        int skip = solve(i + 1, b, prices);

        if (b == 0) {
            int buy = -prices[i] + solve(i + 1, 1, prices);
            return dp[i][b] = max(skip, buy);
        } else {
            int sell = prices[i] + solve(i + 2, 0, prices);
            return dp[i][b] = max(skip, sell);
        }
    }
};