class Solution {
public:
    vector<int> a;
    int dp[303][303];
    int n;
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        a = nums;
        a.insert(a.begin(), 1);
        a.push_back(1);
        n = a.size();

        return f(1, n - 2);
    }

    int f(int i, int j) {
        if (j - i < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxs = INT_MIN;

        for (int k = i; k <= j; k++) {
            int s = a[i - 1] * a[k] * a[j + 1] + f(i, k - 1) + f(k + 1, j);
            maxs = max(maxs, s);
        }

        return dp[i][j] = maxs;
    }
};