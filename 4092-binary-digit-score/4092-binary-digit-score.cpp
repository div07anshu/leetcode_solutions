class Solution {
public:
    int calculateScore(int a, int b) {
        int cnt1 = 0, cnt2 = 0;

        while (a > 0) {
            if (a & 1) {
                cnt1++;
            }

            a = a >> 1;
        }

        while (b > 0) {
            if (b & 1) {
                cnt2++;
            }

            b = b >> 1;
        }

        if (cnt1 >= cnt2) {
            return cnt1 * cnt2;
        }

        return cnt2 / cnt1;
    }
};