class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxn = INT_MIN, minn = INT_MAX;
        vector<int> prefix(n);
        vector<int> suffix(n);

        for (int i = 0; i < n; i++) {
            prefix[i] = max(nums[i], maxn);
            maxn = max(maxn, nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = min(minn, nums[i]);
            minn = min(minn, nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] - suffix[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};