using ll = long long;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        ll low = 1;
        ll high = *max_element(q.begin(), q.end());
        ll ans = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll cnt = 0;

            for (int i = 0; i < q.size(); i++) {
                cnt += (q[i] + mid - 1) / mid;
            }

            if (cnt <= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};