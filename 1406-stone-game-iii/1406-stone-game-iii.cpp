class Solution {
public:
    vector<int> dp;
    vector<bool> vis;
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 <= n)
                dp[i] = nums[i] - dp[i + 1];
            if (i + 2 <= n)
                dp[i] = max(dp[i], nums[i] + nums[i + 1] - dp[i + 2]);
            if (i + 3 <= n)
                dp[i] =
                    max(dp[i], nums[i] + nums[i + 1] + nums[i + 2] - dp[i + 3]);
        }

        int diff = dp[0];

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        }

        return "Tie";
    }
};