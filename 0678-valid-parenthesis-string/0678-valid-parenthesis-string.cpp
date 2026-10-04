class Solution {
public:
    bool checkValidString(string s) {

        int cntl = 0, cntr = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '*') {
                cntl++;
            } else {
                cntl--;
            }

            if (cntl < 0) {
                return false;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                cntr++;
            } else {
                cntr--;
            }

            if (cntr < 0) {
                return false;
            }
        }

        return true;
    }
};