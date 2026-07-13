class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 0, h = q.size();
        int n = nums.size();
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            bool cond = true;
            vector<int> diff(n, 0);

            for (int i = 0; i < mid; i++) {
                int left = q[i][0], rgh = q[i][1], val = q[i][2];
                diff[left] -= val;

                if (rgh + 1 < n) {
                    diff[rgh + 1] += val;
                }
            }

            for (int i = 1; i < n; i++) {
                diff[i] = diff[i] + diff[i - 1];
            }

            for (int i = 0; i < n; i++) {
                if (abs(diff[i]) < nums[i]) {
                    cond = false;
                    break;
                }
            }

            if (cond) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};