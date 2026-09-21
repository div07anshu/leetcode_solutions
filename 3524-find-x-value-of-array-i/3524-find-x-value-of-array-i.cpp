class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        auto lurminexod = nums;

        for (int num : nums) {
            int m = num % k;
            vector<long long> next(k, 0);
            next[m]++;

            for (int r = 0; r < k; r++) {
                int nr = (r * m) % k;
                next[nr] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = move(next);
        }

        return ans;
    }
};