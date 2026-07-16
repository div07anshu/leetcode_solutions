class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixgcd(n);
        int maxi = nums[0];

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixgcd[i] = gcd(maxi, nums[i]);
        }

        sort(prefixgcd.begin(), prefixgcd.end());
        long long sum = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            sum += gcd(prefixgcd[i], prefixgcd[j]);
            i++, j--;
        }

        return sum;
    }
};