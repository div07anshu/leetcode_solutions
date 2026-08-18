class Solution {
public:
    int dp[501][501];
    int stoneGameV(vector<int>& stone) {
        int n = stone.size();
        vector<int> prefix(n + 1, 0);
        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stone[i - 1];
        }

        return solve(0, n - 1, stone, prefix);
    }

    int solve(int st, int ed, vector<int>& stone, vector<int>& prefix) {

        if (st == ed) {
            return 0;
        }

        if (dp[st][ed] != -1) {
            return dp[st][ed];
        }

        // k  decides the split position.....
        int ans = 0;

        for (int k = st; k < ed; k++) {

            int left = prefix[k + 1] - prefix[st];
            int right = prefix[ed + 1] - prefix[k + 1];

            if (left > right) {
                ans = max(ans, right + solve(k + 1, ed, stone, prefix));
            } else if (right > left) {
                ans = max(ans, left + solve(st, k, stone, prefix));
            } else {
                ans = max(ans, left + max(solve(st, k, stone, prefix),
                                          solve(k + 1, ed, stone, prefix)));
            }
        }

        return dp[st][ed] = ans;
    }
};
