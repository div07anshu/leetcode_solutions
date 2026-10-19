class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(begin(nums), end(nums));

        int left = -1, right = -1;
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] == target) {
                left = m;
                h = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        l = 0, h = nums.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                right = m;
                l = m + 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        if (left == -1 || right == -1) {
            return {};
        }

        for (int i = left; i <= right; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};