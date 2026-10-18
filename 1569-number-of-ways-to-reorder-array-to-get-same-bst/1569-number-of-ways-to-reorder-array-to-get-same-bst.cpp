class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    vector<vector<ll>> pt;

    ll solve(vector<int> arr) {
        if (arr.size() < 3) {
            return 1;
        }

        vector<int> left, right;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[0]) {
                right.push_back(arr[i]);
            } else {
                left.push_back(arr[i]);
            }
        }

        ll x = solve(left);
        ll y = solve(right);
        // z = n-1Cr , r == left_size or right_size
        ll z = pt[n - 1][left.size()];

        return ((x * y) % mod * z) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pt.resize(n + 1);

        for (int i = 0; i < n; i++) {
            pt[i] = vector<ll>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                pt[i][j] = (pt[i - 1][j - 1] + pt[i - 1][j]) % mod;
            }
        }

        return (solve(nums) - 1) % mod;
    }
};