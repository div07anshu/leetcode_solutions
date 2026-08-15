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

        if (xorr != 0) {
            return n;
        }

        for (auto x : nums) {
            if (x != 0) {
                return n - 1;
            }
        }

        return 0;
    }
};