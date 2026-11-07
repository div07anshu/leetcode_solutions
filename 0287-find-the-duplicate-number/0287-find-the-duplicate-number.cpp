class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, h = n - 1;
        int ans = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] > m) {
                l = m + 1;
            } else {
                h = m - 1;
                ans = nums[m];
            }
        }

        return ans;
    }
};