class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long minCost = LLONG_MAX;

        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }

            if (j - 1 > 0 && i < n - 1) {
                long long cst = 1LL * i * nums[i] + 1LL * (n - j) * nums[i];
                minCost = min(minCost, cst);
            }

            i = j;
        }

        return minCost;
    }
};