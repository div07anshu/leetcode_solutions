class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> bestminIdx(n, INT_MAX);
        int best = INT_MAX;

        int ans = INT_MAX;
        int sum = 0, l = 0;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target)
                sum -= arr[l++];

            if (sum == target) {
                int len = r - l + 1;

                if (l > 0 && bestminIdx[l - 1] != INT_MAX) {
                    ans = min(ans, len + bestminIdx[l - 1]);
                }

                best = min(best, len);
            }

            bestminIdx[r] = best ;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};