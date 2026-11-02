class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int m = n / 2;
        int val = nums[m];
        int ops = 0;

        for (int i = 0; i < n; i++) {
            ops += abs(nums[i] - val);
        }

        return ops;
    }
};