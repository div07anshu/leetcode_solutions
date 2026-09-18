class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int, int>> seg(26, {-1, -1});

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (seg[c].first == -1)
                seg[c].first = i;

            seg[c].second = i;
        }

        for (int c = 0; c < 26; c++) {
            if (seg[c].first == -1)
                continue;

            int l = seg[c].first;
            int r = seg[c].second;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if (seg[x].first < l) {
                    l = seg[x].first;
                    i = l - 1;
                }

                r = max(r, seg[x].second);
            }

            seg[c] = {l, r};
        }

        sort(seg.begin(), seg.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        vector<string> ans;
        int end = -1;

        for (auto [l, r] : seg) {
            if (l == -1)
                continue;

            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};