class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int cnt = 0;
        while (num) {
            num = num & (num - 1);
            cnt++ ;
        }

        return cnt ;
    }
};