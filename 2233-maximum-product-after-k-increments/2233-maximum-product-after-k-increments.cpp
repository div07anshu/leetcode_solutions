class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int mod = 1e9 + 7;
        for (auto x : nums) {
            pq.push(x);
        }

        while (k--) {
            long long top = pq.top();
            pq.pop();
            pq.push(top + 1);
        }

        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }

        return ans;
    }
};