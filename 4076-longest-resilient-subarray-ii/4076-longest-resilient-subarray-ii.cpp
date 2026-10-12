class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {

        int maxl = 1;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] % k;
        }

        int len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                len++;
                if (((len - 1) * nums[i]) % k == 0) {
                    maxl = max(maxl, len);
                }
            } else {
                len = 1;
            }
        }

        return maxl;
    }
};