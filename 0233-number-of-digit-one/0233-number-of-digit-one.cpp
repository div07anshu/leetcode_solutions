class Solution {
public:
    int dp[10][2];
    int cnt[10][2];
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        memset(cnt, -1, sizeof(cnt));
        string s = to_string(n);
        return solve(0, 1, s);
    }

    int solve(int pos, int tight, string& s) {
        if (pos == s.size()) {
            return 0;
        }

        if (dp[pos][tight] != -1) {
            return dp[pos][tight];
        }

        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;

        for (int i = 0; i <= limit; i++) {
            int newtight = tight && (i == s[pos] - '0');
            ans += solve(pos + 1, newtight, s);

            if (i == 1) {
                ans += nextWays(pos + 1, newtight, s);
            }
        }

        return dp[pos][tight] = ans;
    }

    int nextWays(int pos, int tight, string& s) {
        if (pos == s.size()) {
            return 1;
        }

        if (cnt[pos][tight] != -1) {
            return cnt[pos][tight];
        }

        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;

        for (int i = 0; i <= limit; i++) {
            int newtight = tight && (i == s[pos] - '0');
            ans += nextWays(pos + 1, newtight, s);
        }

        return cnt[pos][tight] = ans;
    }
};