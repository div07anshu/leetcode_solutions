class Solution {
public:
    string removeOuterParentheses(string s) {
        string fin;
        int countr = 0;
        int countl = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                if (countr > countl) {
                    fin.push_back(s[i]);
                }
                countr++;
            }

            else {
                countl++;
                if (countr > countl) {
                    fin.push_back(s[i]);
                }
            }
        }

        return fin;
    }
};