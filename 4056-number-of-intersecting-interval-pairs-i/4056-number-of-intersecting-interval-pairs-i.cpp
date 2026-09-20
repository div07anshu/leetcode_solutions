using vvi = vector<vector<int>>;
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& inter) {
        int cnt = 0;
        int n = inter.size();
        sort(inter.begin(), inter.end());
        for (int i = 0; i < n; i++) {
            cnt += nextidx(i, inter) - i;
        }

        return cnt;
    }

    int nextidx(int i, vvi& inter) {
        int l = i + 1, h = inter.size() - 1;
        int ans = i;

        while (l <= h) {
            int m = l + (h - l) / 2;

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