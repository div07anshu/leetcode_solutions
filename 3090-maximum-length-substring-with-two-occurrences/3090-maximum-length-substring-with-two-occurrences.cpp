class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxl = 1;
        vector<int> hash(26, 0);
        int i = 0, j = 0;

        while (i < n) {
            hash[s[i] - 'a']++;

            while (hash[s[i] - 'a'] > 2) {
                hash[s[j] - 'a']--;
                j++;
            }

            maxl = max(maxl, i - j + 1);
            i++;
        }

        return maxl;
    }
};