using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    int jobScheduling(vi& startTime, vi& endTime, vi& profit) {

        vector<vector<int>> arr;
        int n = profit.size();
        for (int i = 0; i < n; i++) {
            int u = startTime[i], v = endTime[i], p = profit[i];
            arr.push_back({u, v, p});
        }

        sort(arr.begin(), arr.end());
        vector<int> dp(n);
        int maxp = -1;
        dp[n - 1] = arr[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            // not take {option 1}
            dp[i] = dp[i + 1];

            // take
            int low = i + 1, high = n - 1;
            int check = arr[i][1];
            int idx = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid][0] >= check) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (idx != -1) {
                dp[i] = max(dp[i], dp[idx] + arr[i][2]);
            } else {
                dp[i] = max(dp[i], arr[i][2]);
            }
        }

        return dp[0];
    }
};