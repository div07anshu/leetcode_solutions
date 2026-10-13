class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(begin(nums), end(nums));
        long long ans = 0LL;

        int i = 0, j = n - 1;

        while (i <= j) {
            ans += nums[j] - nums[i];
            if (i == j) {
                ans += nums[i];
            }

            i++, j--;
        }

        return ans;
    }
};