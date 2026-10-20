using ll = long long;
long long dp[20][2][2]; // dp[pos][lt][ut]
class Solution {
public:
    string start;
    string suffix;
    int limit;
    string end;
    long long numberOfPowerfulInt(ll st, ll fin, int l, string s) {
        memset(dp, -1, sizeof(dp));

        start = to_string(st);
        end = to_string(fin);
        limit = l;
        suffix = s;
        start = string(end.size() - start.size(), '0') + start;

        return solve(0, 1, 1);
    }

    ll solve(int idx, int lt, int ut) {
        if (idx == end.size()) {
            return 1;
        }

        if (dp[idx][lt][ut] != -1) {
            return dp[idx][lt][ut];
        }

        int suffix_start = end.size() - suffix.size();

        int lb = lt ? start[idx] - '0' : 0;
        int ub = min(limit, ut ? end[idx] - '0' : 9);

        if (idx >= suffix_start) {
            int d = suffix[idx - suffix_start] - '0';

            if (d < lb || d > ub)
                return dp[idx][lt][ut] = 0;

            lb = ub = d;
        }

        ll ans = 0;

        for (int d = lb; d <= ub; d++) {
            int nlt = lt && (d == start[idx] - '0');
            int nut = ut && (d == end[idx] - '0');

            ans += solve(idx + 1, nlt, nut);
        }

        return dp[idx][lt][ut] = ans;
    }
};
