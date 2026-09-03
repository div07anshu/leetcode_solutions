class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int smallodd = INT_MAX;

        for (auto x : nums) {
            if (x % 2) {
                smallodd = min(x, smallodd);
            }
        }

        bool evencond = true, oddcond = true;

        for (auto x : nums) {
            if ((x % 2 == 1) && (x - smallodd < 1)) {
                evencond = false;
                break;
            }
        }

        for (auto x : nums) {
            if ((x % 2 == 0) && (x - smallodd < 1)) {
                oddcond = false;
                break;
            }
        }

        return oddcond || evencond;
    }
};