class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int k = INT_MAX;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                int idx = mp[i];
                k = k & (nums[i] & nums[idx]);
                swap(nums[i], nums[idx]);
                mp[nums[i]] = i;
                mp[nums[idx]] = idx;
            }
        }

        return k == INT_MAX ? 0 : k;
    }
};