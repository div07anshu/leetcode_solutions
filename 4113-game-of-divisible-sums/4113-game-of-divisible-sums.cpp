using vi = vector<int>;
class Solution {
public:
    long long dp[100001];
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        fill(dp, dp + 100001, LLONG_MIN);
        return fun(0, nums);
    }

    long long fun(int i, vi& nums) {
        int n = nums.size();

        if (i >= n) {
            return 0;
        }

        if (dp[i] != LLONG_MIN) {
            return dp[i];
        }

        long long s1 = LLONG_MIN, s2 = LLONG_MIN;

        if (nums[i] % 3 == 0) {
            s1 = nums[i] - fun(i + 1, nums);
        } else {
            s1 = nums[i] + fun(i + 1, nums);
        }

        if (i + 1 < n && (nums[i] + nums[i + 1]) % 3 == 0) {
            s2 = nums[i] + nums[i + 1] - fun(i + 2, nums);
        } else if (i + 1 < n) {
            s2 = nums[i] + nums[i + 1] + fun(i + 2, nums);
        }

        return dp[i] = max(s1, s2);
    }
};