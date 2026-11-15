class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int mini = nums[i];
            for (int j = i; j < n; j++) {
                curr = curr & nums[j];
                mini = min(mini, nums[j]);

                if (curr == mini) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};