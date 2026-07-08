class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        int m = s.size();

        vector<int> digits;
        vector<int> pos;

        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int n = digits.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefNum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;

        vector<int> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + digits[i];

        vector<int> nextIdx(m, n);
        int p = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i)
                p--;
            if (p >= 0 && pos[p] == i)
                nextIdx[i] = p;
            else
                nextIdx[i] = (p + 1 < n ? p + 1 : n);
        }

        vector<int> prevIdx(m, -1);
        p = 0;
        for (int i = 0; i < m; i++) {
            while (p < n && pos[p] < i)
                p++;
            if (p < n && pos[p] == i)
                prevIdx[i] = p;
            else
                prevIdx[i] = p - 1;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int L = nextIdx[l];
            int R = prevIdx[r];

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] - prefNum[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};