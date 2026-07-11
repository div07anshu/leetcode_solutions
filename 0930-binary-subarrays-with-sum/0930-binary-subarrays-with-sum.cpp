class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int gtg = solve(nums, goal);      // greater than equal to goal ;
        int gtg1 = solve(nums, goal - 1); //  greater than equal to goal - 1 ;

        return gtg - gtg1; //  subarray whoose sum are equal to goal ;
    }

    int solve(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }

        int i = 0, j = 0, sum = 0, cnt = 0;
        while (i < nums.size()) {
            sum += nums[i];

            while (sum > goal) {
                sum -= nums[j];
                j++;
            }

            cnt += i - j + 1;
            i++;
        }

        return cnt;
    }
};