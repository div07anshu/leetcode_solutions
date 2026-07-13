class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size(), size = q.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < size; i++) {
            int l = q[i][0], r = q[i][1];
            diff[l] += -1;

            if (r + 1 < n) {
                diff[r + 1] += 1;
            }
        }

        for (int i = 1; i < n; i++) {
            diff[i] = diff[i] + diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (abs(diff[i]) >= nums[i]) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};