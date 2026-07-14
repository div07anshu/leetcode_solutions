class Solution {
public:
    int mod = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxe = *max_element(nums.begin(), nums.end());
        int dp[n + 1][maxe + 1][maxe + 1];

        for (int first = 0; first <= maxe; first++) {
            for (int sec = 0; sec <= maxe; sec++) {
                bool bothNotEmpty = (first != 0 && sec != 0);
                bool gcdEqual = (first == sec);

                dp[n][first][sec] = bothNotEmpty && gcdEqual;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int first = maxe; first >= 0; first--) {
                for (int sec = maxe; sec >= 0; sec--) {
                    int skip = dp[i + 1][first][sec];
                    int take1 = dp[i + 1][gcd(first, nums[i])][sec];
                    int take2 = dp[i + 1][first][gcd(sec, nums[i])];

                    dp[i][first][sec] = (((skip + take1) % mod) + take2) % mod;
                }
            }
        }

        return dp[0][0][0];
    }
};