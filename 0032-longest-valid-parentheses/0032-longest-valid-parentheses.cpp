class Solution {
public:
    int longestValidParentheses(string s) {
        int maxl = 0;
        int n = s.size();
        int open = 0, close = 0;

        for (int i = 0; i < n; i++) {

            if (open < close) {
                open = 0, close = 0;
            }

            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if (open == close) {
                maxl = max(maxl, open + close);
            }
        }

        open = 0, close = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (open > close) {
                open = 0, close = 0;
            }

            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if (open == close) {
                maxl = max(maxl, open + close);
            }
        }

        return maxl;
    }
};