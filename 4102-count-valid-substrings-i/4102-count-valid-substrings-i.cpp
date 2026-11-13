using ll = long long;
class Solution {
public:
    long long countValidSubstrings(string s) {
        ll n = s.size();
        ll cnt = 0;
        ll last = -1;

        for (int i = 0; i < n; i++) {
            if (i >= 2 && s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
                last = i - 2;
            }

            cnt += i - last;
        }

        return cnt;
    }
};