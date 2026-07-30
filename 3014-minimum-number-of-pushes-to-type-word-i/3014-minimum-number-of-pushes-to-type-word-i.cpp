class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int cnt = 0;

        for (auto x : word) {
            cnt++;
            ans += (cnt - 1) / 8 + 1;
        }

        return ans;
    }
};