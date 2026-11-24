class Solution {
public:
    int maxLength(vector<int>& nums) {
        long long n = nums.size();
        int maxl = 0;
        for (int i = 0; i < n; i++) {
            long long g = 0, l = 1;
            long long prod = 1;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                prod = 1LL * prod * nums[j];

                if (prod > 2520 * g * l) {
                    break;
                }

                if (prod == g * l) {
                    maxl = max(maxl, j - i + 1);
                }
            }
        }

        return maxl;
    }
};