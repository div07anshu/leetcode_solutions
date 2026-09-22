class Solution {
public:
    int dp[2501][2501];
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }

    int solve(int i, int prev, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int skip = solve(i + 1, prev, nums);
        int take = 0;

        if (prev == -1) {
            take = 1 + solve(i + 1, i, nums);
        } else if (nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums);
        }

        return dp[i][prev + 1] = max(take, skip);
    }
};