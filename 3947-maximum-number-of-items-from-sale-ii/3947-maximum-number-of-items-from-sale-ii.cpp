class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        int minPrice = INT_MAX;

        for (auto& vec : items) {
            int f = vec[0], p = vec[1];
            minPrice = min(minPrice, p);
            freq[f]++;
        }

        vector<int> freqSum(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int k = i; k <= n; k += i) {
                freqSum[i] += freq[k];
            }
        }

        vector<pair<int, int>> cnt;

        for (auto& vec : items) {
            int f = vec[0], p = vec[1];
            int count = freqSum[f] - 1;

            if (count > 0 && p <= 2 * minPrice) {
                cnt.push_back({f, p});
            }
        }

        sort(cnt.begin(), cnt.end(),
             [&](const pair<int, int> a, const pair<int, int> b) {
                 return a.second < b.second;
             });

        long long res = 0;

        for (auto& vec : cnt) {
            auto [f, p] = vec;

            int ava = freqSum[f] - 1;
            int take = min(budget / p, ava);
            res += 2 * take;
            budget -= take * p;
        }

        res += budget / minPrice;
        return res;
    }
};