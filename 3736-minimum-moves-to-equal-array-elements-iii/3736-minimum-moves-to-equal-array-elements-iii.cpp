class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size(), ops = 0;

        for (int i = 0; i < n; i++) {
            ops += maxi - nums[i];
        }

        return ops;
    }
};