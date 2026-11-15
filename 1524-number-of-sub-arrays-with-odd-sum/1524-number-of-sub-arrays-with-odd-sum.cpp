class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int prev = 0;
        int cnt = 0;
        int even = 1, odd = 0;

        for (int i = 0; i < n; i++) {
            prev += arr[i];
            int curr = prev % 2;

            if (curr == 1) {
                cnt = (cnt + even) % mod;
                odd++;
            } else {
                cnt = (cnt + odd) % mod;
                even++;
            }
        }

        return cnt;
    }
};