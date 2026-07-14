class Solution {
public:
    int dp[201][201][201];
    int mod = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }

    int solve(vector<int>& nums, int i, int g1, int g2) {
        if (i == nums.size()) {
            if (g1 != 0 && g2 != 0 && g1 == g2) {
                return 1;
            }

            return 0;
        }

        if (dp[i][g1][g2] != -1) {
            return dp[i][g1][g2];
        }

        int skip = solve(nums, i + 1, g1, g2);
        int t1 = solve(nums, i + 1, (g1 == 0 ? nums[i] : gcd(g1, nums[i])), g2);
        int t2 = solve(nums, i + 1, g1, (g2 == 0 ? nums[i] : gcd(nums[i], g2)));

        return dp[i][g1][g2] = ((skip + t1) % mod + t2) % mod;
    }
};