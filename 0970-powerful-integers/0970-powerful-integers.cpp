class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> st;

        for (int i = 0; i <= 20; i++) {
            long long a = power(x, i);
            if (a > bound)
                break;

            for (int j = 0; j <= 20; j++) {
                long long b = power(y, j);
                if (a + b > bound)
                    break;

                st.insert(a + b);
            }
        }

        return vector<int>(st.begin(), st.end());
    }

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans *= a;
            a *= a;
            b >>= 1;
        }

        return ans;
    }
};