class Solution {
public:
    int minOperations(string s1, string s2) {
        int ops = 0;
        int n = s1.size();

        if (n == 1) {
            if (s1[0] == s2[0]) {
                return 0;
            } else if (s1[0] == '0') {
                return 1;
            } else {
                return -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i] && s1[i] == '0') {
                s1[i] = '1';
                ops++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == '1' && i < n - 1 && s1[i + 1] == '1') {
                    ops++;
                    s1[i] = s2[i];
                    s1[i + 1] = '0';
                } else if (s1[i] == '0') {
                    ops++;
                    s1[i] = s2[i];
                } else {
                    ops += 2;
                    s1[i] = s2[i];
                }
            }
        }

        return ops;
    }
};