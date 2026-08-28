class Solution {
public:
    char mid = '$';
    string result = "";
    int halflen = 0;

    string lexPalindromicPermutation(string s, string tar) {
        int n = s.size();
        vector<int> cnt(26, 0);
        int cnto = 0;

        for (auto x : s) {
            cnt[x - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                cnto++;
                mid = char(i + 'a');
                if (cnto > 1) {
                    return "";
                }
            }

            cnt[i] = cnt[i] / 2;
        }

        string curr = "";
        halflen = n / 2;
        solve(curr, cnt, tar, 0, false);
        return result;
    }

    bool solve(string& curr, vector<int>& cnt, string& tar, int i, bool g) {
        if (curr.length() == halflen) {
            string lefthalf = curr;
            string righthalf = lefthalf;
            reverse(begin(righthalf), end(righthalf));

            if (mid != '$') {
                lefthalf += mid;
            }

            lefthalf += righthalf;

            if (lefthalf > tar) {
                result = lefthalf;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (cnt[ch - 'a'] == 0) {
                continue;
            }

            if (!g && (ch < tar[i])) {
                continue;
            }

            // do
            curr.push_back(ch);
            cnt[ch - 'a']--;
            bool isGreater = g || ch > tar[i];

            // explore
            if (solve(curr, cnt, tar, i + 1, isGreater)) {
                return true;
            }

            // undo

            curr.pop_back();
            cnt[ch - 'a']++;
        }

        return false;
    }
};