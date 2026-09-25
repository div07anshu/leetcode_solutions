class Solution {
public:
    int dp[32][2][3]; // [digit][tight][prev_digit]
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        string s = binString(n);
        return solve(0, 1, -1, s);
    }

    string binString(int n) {
        string s;
        while (n) {
            s += char('0' + n % 2);
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int solve(int pos, int tight, int prev, string& s) {
        if (pos == s.size()) {
            return 1;
        }

        if (dp[pos][tight][prev + 1] != -1) {
            return dp[pos][tight][prev + 1];
        }

        int ans = 0;
        int limit = tight ? s[pos] - '0' : 1;

        for (int digit = 0; digit <= limit; digit++) {
            if (prev == 1 && digit == 1) {
                continue;
            }

            int newTight = tight && (digit == s[pos] - '0');
            ans += solve(pos + 1, newTight, digit, s);
        }

        return dp[pos][tight][prev + 1] = ans;
    }
};