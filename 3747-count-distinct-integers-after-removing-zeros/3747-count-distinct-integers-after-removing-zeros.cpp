class Solution {
public:
    long long dp[16][2];
    long long countDistinct(long long n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        long long ans = 0;
        int m = s.size();

        for (int len = 1; len < m; len++) {
            ans += 1LL * pow(9, len);
        }
        ans = ans + solve(0, 1, s);
        return ans;
    }

    long long solve(int pos, int tight, string& s) {
        if (pos == s.size()) {
            return 1;
        }

        if (dp[pos][tight] != -1) {
            return dp[pos][tight];
        }

        int limit = tight ? s[pos] - '0' : 9;
        long long ans = 0;

        for (int d = 1; d <= limit; d++) {
            int newTight = tight && (d == s[pos] - '0');
            ans += solve(pos + 1, newTight, s);
        }

        return dp[pos][tight] = ans;
    }
};