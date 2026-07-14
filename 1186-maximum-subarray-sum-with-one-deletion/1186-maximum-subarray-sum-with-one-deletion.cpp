class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp0(n);
        vector<int> dp1(n);
        int sum = INT_MIN;
        dp0[0] = arr[0];
        dp1[0] = INT_MIN;

        for (int i = 1; i < n; i++) {
            dp0[i] = max(arr[i], dp0[i - 1] + arr[i]);
        }

        for (int i = 1; i < n; i++) {
            if (dp1[i - 1] == INT_MIN) {
                dp1[i] = dp0[i - 1];
            } else {
                dp1[i] = max(dp0[i - 1], dp1[i - 1] + arr[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            sum = max({sum, dp0[i], dp1[i]});
        }

        return sum;
    }
};