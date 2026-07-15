class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo = (n * (2 + (n - 1) * 2)) / 2;
        int sume = (n * (4 + (n - 1) * 2)) / 2;

        return gcd(sumo, sume);
    }
};