class Solution {
public:
    int getSum(int a, int b) {

        // a --> stores the partial sum ;
        // b --> stores the carry ;

        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a ;
    }
};