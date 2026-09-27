class Solution {
public:
    unordered_map<int, int> dp[10][2][2][100][2];
    string l, r;

    int beautifulNumbers(int left, int right) {
        l = to_string(left);
        r = to_string(right);

        l = string(r.size() - l.size(), '0') + l;

        return solve(0, 1, 1, 1, 0, 0);
    }

    int solve(int pos, int lt, int ut, int p, int s, int st) {

        if (pos == r.size()) {
            if (!st)
                return 0;
            return p % s == 0;
        }

        auto& mp = dp[pos][lt][ut][s][st];

        if (mp.count(p))
            return mp[p];

        int lb = lt ? l[pos] - '0' : 0;
        int ub = ut ? r[pos] - '0' : 9;

        int ans = 0;

        for (int d = lb; d <= ub; d++) {

            int nlt = lt && (d == l[pos] - '0');
            int nut = ut && (d == r[pos] - '0');

            if (!st && d == 0) {
                ans += solve(pos + 1, nlt, nut, 1, s, 0);
            } else {
                ans += solve(pos + 1, nlt, nut, p * d, s + d, 1);
            }
        }

        return mp[p] = ans;
    }
};