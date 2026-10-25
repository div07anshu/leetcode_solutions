class Solution {
public:
    using ll = long long;
    long long maximizeSum(vector<int>& nums, int k) {
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        priority_queue<ll> pq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            auto [num, x] = delta(nums[i]);
            pq.push(num - x);
        }

        while (k-- && !pq.empty()) {
            ll diff = pq.top();
            pq.pop();
            sum += diff;
        }

        return sum;
    }

    pair<ll, ll> delta(int n) {
        vector<int> v;
        int x = n;

        while (n > 0) {
            v.push_back(n % 10);
            n = n / 10;
        }

        sort(v.rbegin(), v.rend());
        long long num = 0;

        for (int i = 0; i < v.size(); i++) {
            num = 10 * num + v[i];
        }

        return {num, x};
    }
};