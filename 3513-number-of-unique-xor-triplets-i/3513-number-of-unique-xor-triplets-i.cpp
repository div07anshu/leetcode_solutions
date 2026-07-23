class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        int m = msb(n);
        return (pow(2, m + 1));
    }

    int msb(int x) {
        int idx = -1;

        while (x > 0) {
            x = x / 2;
            idx++;
        }

        return idx;
    }
};