class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int xorr = 0;

        for (int x : nums) {
            xorr = xorr ^ x;
            mp[x]++;
        }

        if (xorr == 0) {
            if (mp.size() == 1 && mp[0] == n) {
                return 0;
            }

            return n - 1;

        } else {
            return n;
        }
    }
};