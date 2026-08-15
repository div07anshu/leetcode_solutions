class Solution {
public:
    long long waysToBuyPensPencils(int total, int pen, int pencil) {
        long long ways = 0;
        long long cntpen = 0;

        while (true) {
            long long left = total - pen * cntpen;

            if (left < 0) {
                break;
            }

            long long cntpencil = left / pencil;
            ways += cntpencil + 1;
            cntpen++;
        }

        return ways;
    }
};