using s = string;
class Solution {
public:
    const int mod = 1e9 + 7;
    int mini, maxi;
    string s1, s2;
    int dp[30][2][2][200];
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        mini = min_sum, maxi = max_sum;
        s1 = num1, s2 = num2;
        int diff = s2.size() - s1.size();
        string temp;

        for (int i = 0; i < diff; i++) {
            temp += '0';
        }

        s1 = temp + s1;

        return solve(0, 1, 1, 0);
    }

    int solve(int pos, int lt, int ut, int sum) {

        if (pos == s2.size()) {
            return (sum >= mini && sum <= maxi);
        }

        if (dp[pos][lt][ut][sum] != -1) {
            return dp[pos][lt][ut][sum];
        }

        int ub = ut ? s2[pos] - '0' : 9;
        int lb = lt ? s1[pos] - '0' : 0;
        long long ans = 0;

        for (int d = lb; d <= ub; d++) {
            int nut = ut && (d == s2[pos] - '0');
            int nlt = lt && (d == s1[pos] - '0');
            ans = (ans + solve(pos + 1, nlt, nut, sum + d)) % mod;
        }

        return dp[pos][lt][ut][sum] = ans;
    }
};