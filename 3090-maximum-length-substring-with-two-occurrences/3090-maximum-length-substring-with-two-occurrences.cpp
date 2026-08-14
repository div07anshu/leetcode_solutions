class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxl = 1;
        unordered_map<char, int> mp;
        int i = 0, j = 0;

        while (i < n) {
            mp[s[i]]++;

            while (mp[s[i]] > 2) {
                mp[s[j]]--;
                j++;
            }

            maxl = max(maxl, i - j + 1);
            i++;
        }

        return maxl;
    }
};