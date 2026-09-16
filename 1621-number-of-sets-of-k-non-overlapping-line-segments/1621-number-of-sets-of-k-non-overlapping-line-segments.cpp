class Solution {
public:
    const long long MOD = 1e9 + 7;

    int dp[1001][1001];
    int sum[1001][1001];

    int solve(int n, int k, int idx) {
        if (k == 0)
            return 1;

        if (idx >= n)
            return 0;

        if (dp[k][idx] != -1)
            return dp[k][idx];

        long long skip = solve(n, k, idx + 1);
        long long take = getSum(n, k - 1, idx + 1);

        return dp[k][idx] = (skip + take) % MOD;
    }

    int getSum(int n, int k, int idx) {
        if (idx >= n)
            return 0;

        if (sum[k][idx] != -1)
            return sum[k][idx];

        return sum[k][idx] = (solve(n, k, idx) + getSum(n, k, idx + 1)) % MOD;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        memset(sum, -1, sizeof(sum));
        return solve(n, k, 0);
    }
};