using vi = vector<int>;
class Solution {
public:
    long long minSumSquareDiff(vi& nums1, vi& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<long long> diff(n);
        long long sum = 0;
        long long mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (k >= sum)
            return 0;

        long long l = 0, h = mx;
        long long ans = mx;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long need = 0;

            for (auto d : diff) {
                need += max(0LL, d - mid);
            }

            if (need <= k) {
                h = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        long long res = 0;
        long long used = 0;

        for (auto d : diff) {
            long long final_diff = min(d, ans);
            used += max(0LL, d - ans);
            res += 1LL * final_diff * final_diff;
        }

        long long rem = k - used;
        res -= rem * (2 * ans - 1);
        return res;
    }
};