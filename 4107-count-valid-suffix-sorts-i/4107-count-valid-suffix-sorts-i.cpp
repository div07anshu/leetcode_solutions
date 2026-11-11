class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int ci = -1;
        int n = nums.size();
        vector<int> freq(100001, 0);

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            freq[target[i]]--;
        }

        for (auto x : freq) {
            if (x != 0) {
                return 0;
            }
        }

        if (n == 1) {
            return nums[0] == target[0];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                break;
            }

            ci = i;
        }

        for (int i = ci + 1; i < n - 1; i++) {
            if (target[i] < target[i + 1]) {
                return 0;
            }
        }

        int cnt = 1;
        int i = ci + 1;

        if (ci + 1 >= n) {
            i = ci;
        }

        while (i > 0) {
            if (target[i - 1] >= target[i]) {
                cnt++;
                i--;
            } else {
                break;
            }
        }

        return cnt;
    }
};