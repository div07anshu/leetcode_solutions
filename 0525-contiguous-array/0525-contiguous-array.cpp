class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, n = nums.size();
        int maxl = 0;
        unordered_map<int, int> mp; // sum , idx
        mp[0] = -1;

        for (int i = 0; i < n; i++) {

            if (nums[i]) {
                sum += 1;
            } else {
                sum -= 1;
            }

            if (mp.count(sum)) {
                maxl = max(maxl, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return maxl;
    }
};