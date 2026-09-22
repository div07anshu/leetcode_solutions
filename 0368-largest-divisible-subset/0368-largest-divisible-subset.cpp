using vi = vector<int>;
class Solution {
public:
    vector<int> ans;
    int dp[1001][1001];
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        solve(0, -1, nums);
        vector<int> ans;

        int i = 0, prev = -1;

        while (i < n) {

            int skip = solve(i + 1, prev, nums);
            int take = -1;

            if (prev == -1 || (nums[i] % nums[prev] == 0)) {
                take = 1 + solve(i + 1, i, nums);
            }

            if (take >= skip) {
                ans.push_back(nums[i]);
                prev = i;
            }

            i++;
        }

        return ans;
    }

    int solve(int i, int prev, vector<int>& nums) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int skip = solve(i + 1, prev, nums);
        int take = 0;

        if (prev == -1 || nums[i] % nums[prev] == 0) {
            take = 1 + solve(i + 1, i, nums);
        }

        return dp[i][prev + 1] = max(take, skip);
    }
};