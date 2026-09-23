class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int req = tot - x;

        if(req < 0) return -1 ;
        
        int sum = 0;
        int minl = INT_MAX;

        int i = 0, j = 0;

        while (i < n) {
            sum += nums[i];

            while (sum > req) {
                sum -= nums[j++];
            }

            if (sum == req) {
                minl = min(n - i + j - 1, minl);
            }
            i++;
        }

        return minl == INT_MAX ? -1 : minl;
    }
};