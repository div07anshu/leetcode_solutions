using vi = vector<int>;
class Solution {
public:
    int dp[50001][2];
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        return solve(0, 0, prices, fee);
    }

    int solve(int i, int b, vi& p, int fee) {
        if (i >= p.size()) {
            return 0;
        }

        if (dp[i][b] != -1) {
            return dp[i][b];
        }

        int skip = solve(i + 1, b, p, fee);
        if (b == 0) {
            int buy = -p[i] + solve(i + 1, 1, p, fee);
            return dp[i][b] = max(buy, skip);
        } else {
            int sell = p[i] - fee + solve(i + 1, 0, p, fee);
            return dp[i][b] = max(sell, skip);
        }
    }
};