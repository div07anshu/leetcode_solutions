int dp[100001];
class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return solve(0, cost);
    }

    int solve(int idx, vector<int>& cost) {

        if (idx >= cost.size()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = INT_MAX;

        for (int i = 1; i <= 3; i++) {
            if (idx + i <= cost.size()) {
                int cst = cost[idx + i - 1] + i * i + solve(idx + i, cost);
                ans = min(ans, cst);
            }
        }

        return dp[idx] = ans;
    }
};