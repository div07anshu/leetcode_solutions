using vi = vector<int>;
using ll = long long;
class Solution {
public:
    vector<int> successfulPairs(vi& s, vi& p, ll suc) {
        sort(begin(p), end(p));
        int n = s.size(), m = p.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int l = 0, h = m - 1;
            int pos = m;

            while (l <= h) {
                int m = l + (h - l) / 2;

                if (1LL * s[i] * p[m] >= suc) {
                    pos = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }

            res.push_back(m - pos);
        }

        return res;
    }
};