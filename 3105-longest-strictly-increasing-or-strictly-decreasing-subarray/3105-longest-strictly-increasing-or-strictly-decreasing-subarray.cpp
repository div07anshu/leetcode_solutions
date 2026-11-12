class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int maxl = 1, n = arr.size();
        int len = 1;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                len++;
            } else {
                maxl = max(maxl, len);
                len = 1;
            }

            maxl = max(maxl, len);
        }

        len = 1;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                len++;
            } else {
                maxl = max(maxl, len);
                len = 1;
            }

            maxl = max(maxl, len);
        }

        return maxl;
    }
};