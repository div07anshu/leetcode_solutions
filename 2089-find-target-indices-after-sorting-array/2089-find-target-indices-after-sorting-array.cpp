class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int tar) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        auto left = lower_bound(nums.begin(), nums.end(), tar) - nums.begin();
        auto right = upper_bound(nums.begin(), nums.end(), tar) - nums.begin();

        for (int i = left; i < right; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};