class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        map<char, int> mp;
        priority_queue<pair<int, char>> pq; // freq , char
        int cnt = 0;
        int ans = 0;

        for (auto x : word) {
            mp[x]++;
        }

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        while (!pq.empty()) {
            cnt++;
            auto [freq, x] = pq.top();
            pq.pop();
            ans += ((cnt - 1) / 8 + 1) * freq;
        }

        return ans;
    }
};