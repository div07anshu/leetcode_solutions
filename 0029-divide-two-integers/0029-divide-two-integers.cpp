class Solution {
public:
    int divide(int divid, int divi) {
        bool neg = (divid < 0) ^ (divi < 0);
        long long dividend = abs(1LL * divid);
        long long divisor = abs(1LL * divi);
        long long quotient = 0;

        for (int i = 31; i >= 0; i--) {
            if ((divisor << i) <= dividend) {
                dividend -= (divisor << i);
                quotient |= (1LL << i);
            }
        }

        if (neg) {
            quotient = -quotient;
        }

        if (quotient > INT_MAX) {
            return INT_MAX;
        } else if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return quotient;
    }
};