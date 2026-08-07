class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxl = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long g = gcd(nums[i], nums[j]);
                long long num = (1LL * nums[j] / g) * (1LL * nums[i] / g);
                maxl = max(maxl, num);
            }
        }

        return maxl;
    }
};