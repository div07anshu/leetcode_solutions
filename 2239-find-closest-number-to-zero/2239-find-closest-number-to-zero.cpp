class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mind = INT_MAX;
        int n = nums.size();
        int minn = INT_MIN;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums[i]);

            if (diff < mind) {
                mind = diff;
                minn = nums[i];
            } else if (diff == mind) {
                minn = max(minn, nums[i]);
            }
        }

        return minn;
    }
};