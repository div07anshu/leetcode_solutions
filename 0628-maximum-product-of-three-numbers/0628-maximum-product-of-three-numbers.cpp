class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxf, maxs, maxt, minf, mins;
        maxf = nums[n - 1], maxs = nums[n - 2], maxt = nums[n - 3];
        minf = nums[0], mins = nums[1];

        return max(maxf * maxs * maxt, minf * mins * maxf);
    }
};