class Solution {
public:
    int dp[10][1024];
    int countNumbersWithUniqueDigits(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, 0);
    }

    int solve(int pos, int n, int mask) {
        if (pos == n) {
            return 1;
        }

        if (dp[pos][mask] != -1) {
            return dp[pos][mask];
        }

        int ans = 0;

        for (int i = 0; i <= 9; i++) {

            if (mask & (1 << i)) {
                continue;
            }

            int newMask = -1;

            if (i == 0 && mask == 0) {
                newMask = mask;
            } else {
                newMask = mask | (1 << i);
            }

            ans += solve(pos + 1, n, newMask);
        }

        return dp[pos][mask] = ans;
    }
};