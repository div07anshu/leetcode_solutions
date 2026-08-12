class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxf = 0;
        int maxn = -1;
        int n = nums.size();
        int maxl = 1;
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        while (i < n) {
            mp[nums[i]]++;

            while (mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }

            maxl = max(maxl, i - j + 1);
            i++;
        }

        return maxl;
    }
};