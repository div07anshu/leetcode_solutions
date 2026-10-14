class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        while (sum > 0 && num > 0) {
            if (sum > 9) {
                ans += '9';
                sum -= 9;
            } else {
                ans += char(sum + '0');
                sum = 0;
            }

            num--;
        }

        if (num == 0 && sum > 0) {
            return "";
        }

        for (int i = 0; i < num; i++) {
            ans += '0';
        }

        return ans;
    }
};