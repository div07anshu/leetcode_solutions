class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> hash(26, 0);
        int n = s.size();
        string l = "";
        string mid = "";

        for (auto x : s) {
            hash[x - 'a']++;
        }

        for (int k = 0; k < 26; k++) {
            char x = 'a' + k;
            int freq = hash[k];

            for (int i = 0; i < freq / 2; i++) {
                l += x;
            }

            if (freq % 2 != 0) {
                mid += x;
            }
        }

        string start = l;
        reverse(l.begin(), l.end());

        return start + mid + l;
    }
};