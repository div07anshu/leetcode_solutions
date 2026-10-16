class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    int n;
    vector<int> sum;
    vector<int> lazy;
    vector<int> sq;

    void update_query(int s, int e, int i, int l, int r, int val) {

        if (lazy[i] != 0) {
            apply_lazy(i, l, r, lazy[i]);
            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }

            lazy[i] = 0;
        }

        if (r < s || l > e || l > r) {
            return;
        }

        if (l >= s && r <= e) {
            apply_lazy(i, l, r, val);

            if (l != r) {
                lazy[2 * i + 1] += val;
                lazy[2 * i + 2] += val;
            }
            return;
        }

        int mid = l + (r - l) / 2;
        update_query(s, e, 2 * i + 1, l, mid, val);
        update_query(s, e, 2 * i + 2, mid + 1, r, val);

        sum[i] = (sum[2 * i + 1] + sum[2 * i + 2]) % mod;
        sq[i] = (sq[2 * i + 1] + sq[2 * i + 2]) % mod;
    }

    void apply_lazy(int i, int l, int r, int val) {
        ll len = r - l + 1;
        sq[i] = (sq[i] + 2LL * val * sum[i] + len * val * val) % mod;
        sum[i] = (sum[i] + len * val) % mod;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.resize(4 * n, 0);
        sq.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        vector<int> vis(100001, -1);
        ll result = 0;

        for (int i = 0; i < n; i++) {
            int s = vis[nums[i]] + 1;
            int e = i;
            update_query(s, e, 0, 0, n - 1, 1);
            result = (result + sq[0]) % mod;
            vis[nums[i]] = i;
        }

        return result;
    }
};