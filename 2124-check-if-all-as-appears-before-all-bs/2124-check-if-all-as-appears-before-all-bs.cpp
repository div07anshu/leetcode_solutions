class Solution {
public:
    bool checkString(string s) {
        bool lb = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && lb == true) {
                return false;
            } else if (s[i] == 'b') {
                lb = true;
            }
        }

        return true;
    }
};