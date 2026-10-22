class Solution {
public:
    int minOperations(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }

        int ans = solve(nums);
        reverse(nums.begin(), nums.end());
        ans = min(ans, solve(nums) + 1); // one extra bcz of reversing..
        return ans == 1e9 ? -1 : ans;
    }

    int solve(vector<int>& nums) {
        vector<int> v = nums;
        int n = nums.size();

        for (int x : nums) {
            v.push_back(x);
        }

        int count = 1;
        // increasing

        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[i - 1]) {
                count = 1;
            } else {
                count++;

                if (count == n) {
                    return i + 1 - n;
                }
            }
        }

        count = 1;
        // decreasing

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[i - 1]) {
                count = 1;
            } else {
                count++;

                if (count == n) {
                    return i + 2 - n;
                }
            }
        }

        return 1e9;
    }
};