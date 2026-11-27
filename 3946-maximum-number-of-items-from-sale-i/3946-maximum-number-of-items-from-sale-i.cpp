
class Solution {
public:
    int n;
    int dp[1001][1501][2];

    using vi = vector<int>;
    vector<vector<int>> vp;

    int solve(int idx, int bg, int cond, vi& cpy) {
        if (idx >= n || bg <= 0)
            return 0;

        int& ans = dp[idx][bg][cond];

        if (ans != -1)
            return ans;

        int take = 0;

        if (bg >= vp[idx][1]) {
            take = 1 + solve(idx, bg - vp[idx][1], 1, cpy);

            if (cond == 0)
                take += cpy[idx];
        }

        int ntake = solve(idx + 1, bg, 0, cpy);

        return ans = max(take, ntake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        vp = items;

        memset(dp, -1, sizeof(dp));

        vi cpy(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    cpy[i]++;
                }
            }
        }

        return solve(0, budget, 0, cpy);
    }
};
