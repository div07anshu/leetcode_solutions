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
                int mid = l + (h - l) / 2;

                if (1LL * s[i] * p[mid] >= suc) {
                    pos = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            res.push_back(m - pos);
        }

        return res;
    }
};