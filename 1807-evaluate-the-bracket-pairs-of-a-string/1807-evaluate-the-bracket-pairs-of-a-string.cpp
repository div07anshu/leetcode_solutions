class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        string ans;

        for (auto k : knowledge) {
            mp[k[0]] = k[1];
        }

        string temp = "";
        bool cond = false;

        for (auto x : s) {
            if (x == '(') {
                cond = true;
            } else if (x == ')') {
                ans += mp.count(temp) ? mp[temp] : "?";
                temp = "";
                cond = false;
            }

            if (cond && x != '(') {
                temp += x;
            } else if (!cond && x != ')') {
                ans += x;
            }
        }

        return ans;
    }
};