class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        map<char, int> mp;

        for (auto c : s) {
            mp[c]++;
        }

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        if (s[0] == mx && s[n - 1] == mn) {
            if (mp[mx] > 1 || mp[mn] > 1) {
                return 2;
            }

            return 3;
        }

        return 2;
    }
};