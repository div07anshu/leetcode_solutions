class Solution {
public:
    const long long mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int b = 0; b <= 31; b++) {
                if (nums[i] & (1 << b)) {
                    cnt[b]++;
                }
            }
        }

        while (k--) {
            long long num = 0;

            for (int i = 0; i < 32; i++) {
                if (cnt[i] > 0) {
                    num = num | (1 << i);
                    cnt[i]--;
                }
            }

            sum = (sum + num * num) % mod;
        }

        return sum;
    }
};