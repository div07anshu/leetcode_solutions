using ll = long long;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> cumm(n);
        cumm[0] = nums[0];

        for (int i = 1; i < n; i++) {
            cumm[i] = cumm[i - 1] + nums[i];
        }

        auto rangeSum = [&](int i, int j) -> long long {
            if (i > j) {
                return 0;
            }
            return cumm[j] - ((i > 0) ? cumm[i - 1] : 0);
        };

        // we took invalid idx n as ngr of n-1 will be n
        vector<int> ngr(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                ngr[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // total ops to make i to n-1 increasing
        vector<ll> ops(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int m = ngr[i];
            // operations to make i to m-1 increasing
            ll operation = (1LL * nums[i] * (m - i)) - rangeSum(i, m - 1);
            ops[i] = operation + ops[m];
        }

        deque<int> dq;
        ll result = 0;
        int i = 0, j = 0;
        while (j < n) {

            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            while (i <= j) {
                int m = dq.front();

                ll cnt = (ops[i] - ops[m]) + (1LL * nums[m] * (j - m + 1)) -
                         rangeSum(m, j);

                if (cnt <= k) {
                    break;
                }

                i++;
                if (dq.front() < i) {
                    dq.pop_front();
                }
            }

            result += j - i + 1;
            j++;
        }

        return result;
    }
};