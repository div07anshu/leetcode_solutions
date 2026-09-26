class Solution {
public:
    // [pos][tight][mask][started];
    int dp[10][2][1024][2];
    int numDupDigitsAtMostN(int n) {
        // n - cnt(non-repeated_digit)
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return n - solve(0, 1, 0, 0, s);
    }

    int solve(int pos, int tight, int mask, int st, string& s) {
        if (pos == s.size()) {
            return st;
        }

        if (dp[pos][tight][mask][st] != -1) {
            return dp[pos][tight][mask][st];
        }

        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;
        for (int d = 0; d <= limit; d++) {
            int newTight = tight && (d == s[pos] - '0');

            if (!st && d == 0) {
                ans += solve(pos + 1, newTight, mask, 0, s);
            } else {
                if (mask & (1 << d)) {
                    continue;
                }

                ans += solve(pos + 1, newTight, mask | (1 << d), 1, s);
            }
        }

        return dp[pos][tight][mask][st] = ans;
    }
};