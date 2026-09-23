class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long cnt = 0;
        int curr = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            curr = curr ^ nums[i];
            if (mp.count(curr)) {
                cnt += mp[curr];
            }

            mp[curr]++;
        }

        return cnt ;
    }
};