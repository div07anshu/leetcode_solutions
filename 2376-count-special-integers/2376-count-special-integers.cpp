class Solution {
public:
    int dp[10][2][1024];
    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return solve(0, 1, 0, s);
    }

    int solve(int pos, int tight, int mask, string s) {
        if (pos >= s.size()) {
            return mask > 0;
        }

        if (dp[pos][tight][mask] != -1) {
            return dp[pos][tight][mask];
        }

        int ans = 0;

        if (tight == 1) {
            for (int i = 0; i <= s[pos] - '0'; i++) {

                if (mask & (1 << i)) {
                    continue;
                }

                int newMask = -1;

                if (i == 0 && mask == 0) {
                    newMask = mask;
                } else {
                    newMask = mask | (1 << i);
                }

                if (i == s[pos] - '0') {
                    ans += solve(pos + 1, 1, newMask, s);
                } else {
                    ans += solve(pos + 1, 0, newMask, s);
                }
            }

        } else {
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

                ans += solve(pos + 1, 0, newMask, s);
            }
        }

        return dp[pos][tight][mask] = ans;
    }
};