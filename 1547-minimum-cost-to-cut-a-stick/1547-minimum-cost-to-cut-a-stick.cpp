class Solution {
public:
    int dp[103][103];
    vector<int> arr;
    int minCost(int size, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        arr = cuts;
        arr.insert(arr.begin(), 0);
        arr.push_back(size);
        int n = arr.size();
        sort(begin(arr), end(arr));
        return f(0, n - 1, size);
    }

    int f(int i, int j, int l) {
        if (j - i <= 1) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mincst = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int c = l + f(i, k, arr[k] - arr[i]) + f(k, j, arr[j] - arr[k]);
            mincst = min(mincst, c);
        }

        return dp[i][j] = mincst;
    }
};