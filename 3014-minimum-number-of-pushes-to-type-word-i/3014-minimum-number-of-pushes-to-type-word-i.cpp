class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        map<char, int> mp;
        int cnt = 0;

        for (auto x : word) {
            mp[x]++;
        }

        for (auto it : mp) {
            cnt++;
            char x = it.first;
            int freq = it.second;

            ans += (cnt / 8 + (cnt % 8 != 0)) * freq;
        }

        return ans ;
    }
};