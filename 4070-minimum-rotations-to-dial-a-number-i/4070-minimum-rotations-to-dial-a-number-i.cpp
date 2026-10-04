class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int cnt = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int fin = s[i] - '0';
            int d = abs(fin - prev);
            cnt += min(d, 10 - d);
            prev = fin;
        }

        return cnt;
    }
};