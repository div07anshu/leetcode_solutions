class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int hash[51] = {0};

        if (k == 1 || k == n) {
            int maxi = INT_MIN;

            for (auto x : nums) {
                hash[x]++;
                maxi = max(maxi, x);
            }

            if (k == n)
                return maxi;

            for (int i = 50; i >= 0; i--) {
                if (hash[i] == 1) {
                    return i;
                }
            }

        } else {

            for (auto x : nums) {
                hash[x]++;
            }
        }

        if (hash[nums[0]] == 1 && hash[nums[n - 1]] == 1)
            return max(nums[0], nums[n - 1]);

        if (hash[nums[0]] == 1) {
            return nums[0];
        }

        if (hash[nums[n - 1]] == 1) {
            return nums[n - 1];
        }

        return -1;
    }
};