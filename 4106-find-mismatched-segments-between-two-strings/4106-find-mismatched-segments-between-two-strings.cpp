class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.size();
        string mis1 = "", mis2 = "";

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                mis1 += s1[i];
                mis2 += s2[i];
            } else if (mis1 != "") {
                ans.push_back({mis1, mis2});
                mis1 = "", mis2 = "";
            }
        }

        if (mis1 != "") {
            ans.push_back({mis1, mis2});
            mis1 = "", mis2 = "";
        }

        return ans;
    }
};