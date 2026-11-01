class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int ops = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ops += nums[i] - mini;
        }

        return ops;
    }
};