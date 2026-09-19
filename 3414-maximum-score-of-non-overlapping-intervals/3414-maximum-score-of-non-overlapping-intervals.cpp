using vvi = vector<vector<int>>;
using vi = vector<int>;

class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> dp;
    vector<int> nxt;

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        dp.assign(n + 1, vector<Node>(5));
        nxt.resize(n);

        for (int i = 0; i < intervals.size(); i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++) {
            nxt[i] = nextIdx(i, intervals);
        }

        return solve(intervals, 0, 4).idxs;
    }

    int nextIdx(int i, vvi& inter) {
        int l = i + 1, h = inter.size() - 1;
        int ans = inter.size();
        while (l <= h) {
            int m = l + (h - l) / 2;

            if (inter[m][0] > inter[i][1]) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }

    Node solve(vvi& inter, int i, int k) {
        if (k == 0 || i >= inter.size()) {
            return Node();
        }

        if (dp[i][k].score != -1) {
            return dp[i][k];
        }

        int wt = inter[i][2], idx = inter[i][3];
        int j = nxt[i];

        Node skip = solve(inter, i + 1, k); // skip
        Node temp = solve(inter, j, k - 1); // take

        Node take;
        take.score = wt + temp.score;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);
        sort(begin(take.idxs), end(take.idxs));

        Node result;

        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return dp[i][k] = result;
    }
};