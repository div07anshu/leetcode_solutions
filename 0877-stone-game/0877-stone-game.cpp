class Solution {
public:
    vector<vector<int>> dp;
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));
        int tot = accumulate(piles.begin(), piles.end(), 0);
        int p1 = solve(0, n - 1, piles);
        int p2 = tot - p1;

        return p1 > p2;
    }

    int solve(int i, int j, vector<int>& nums) {
        if (i > j) {
            return 0;
        }

        if (i == j) {
            return nums[i];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ti =
            nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int tj =
            nums[j] + min(solve(i, j - 2, nums), solve(i + 1, j - 1, nums));

        return dp[i][j] = max(ti, tj);
    }
};