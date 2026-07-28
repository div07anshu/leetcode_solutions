class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        int n = s.size();
        string l = "";
        string mid = "";

        for (auto x : s) {
            mp[x]++;
        }

        for (auto it : mp) {
            char x = it.first;
            int freq = it.second;

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