using vvi = vector<vector<int>>;
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& inter) {
        long long cnt = 0;
        long long n = inter.size();
        sort(inter.begin(), inter.end());
        for (int i = 0; i < n; i++) {
            cnt += nextidx(i, inter) - i;
        }

        return cnt;
    }

    long long nextidx(int i, vvi& inter) {
        long long l = i + 1, h = inter.size() - 1;
        long long ans = i;

        while (l <= h) {
            long long m = l + (h - l) / 2;

            if (inter[m][0] <= inter[i][1]) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
};