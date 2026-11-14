class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int i = 0, j = 0;
        int n = nums.size();
        int mins = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (j - i + 1 <= r && j - i + 1 >= l && sum > 0) {
                    mins = min(mins, sum);
                }
            }
        }

        return mins == INT_MAX ? -1 : mins;
    }
};