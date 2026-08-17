class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k == 0) {
                ans[i] = 0;
            } else if (k < 0) {
                int a = -1 * k;
                for (int j = i - 1; j >= i - a; j--) {
                    sum += code[(j + n) % n];
                }
                ans[i] = sum;
            } else {
                for (int j = i + 1; j <= i + k; j++) {
                    sum += code[(j + n) % n];
                }
                ans[i] = sum;
            }
        }

        return ans;
    }
};