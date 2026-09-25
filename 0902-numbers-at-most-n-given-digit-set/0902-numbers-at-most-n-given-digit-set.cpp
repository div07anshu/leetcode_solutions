class Solution {
public:
    vector<int> arr;
    int dp[10][2];
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);

        for (auto x : digits) {
            arr.push_back(x[0] - '0');
        }

        int m = s.size();
        int ans = 0;

        for (int len = 1; len < m; len++) {
            ans += (int)pow(arr.size(), len);
        }

        ans += solve(0, 1, s);
        return ans;
    }

    int solve(int pos, int tight, string& s) {
        if (pos == s.size()) {
            return 1;
        }

        if (dp[pos][tight] != -1) {
            return dp[pos][tight];
        }

        int ans = 0;
        int limit = tight ? (s[pos] - '0') : 9;

        for (auto d : arr) {
            if (d > limit) {
                break;
            }

            int newTight = tight && (d == (s[pos] - '0'));
            ans += solve(pos + 1, newTight, s);
        }

        return dp[pos][tight] = ans;
    }
};