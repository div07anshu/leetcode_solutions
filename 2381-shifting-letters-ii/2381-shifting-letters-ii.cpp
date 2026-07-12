class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shift) {
        int n = s.size(), size = shift.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < size; i++) {
            int l = shift[i][0], r = shift[i][1], dir = shift[i][2];
            diff[l] += (dir == 1 ? 1 : -1);

            if (r + 1 < n) {
                diff[r + 1] += (dir == 1 ? -1 : 1);
            }
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int ascii = s[i] - 'a';
            ascii = (ascii + (diff[i] % 26) + 26) % 26;
            s[i] = ascii + 'a';
        }

        return s;
    }
};