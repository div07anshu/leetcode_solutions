class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        string temp;
        set<string> ans;
        solve(0, temp, ans, s, 0);
        return vector<string>(ans.begin(), ans.end());
    }

    void solve(int i, string& temp, set<string>& ans, string& s, int cnt) {
        if (i == s.size()) {
            if (isValid(temp)) {
                if (ans.empty() || temp.size() > ans.begin()->size()) {
                    ans.clear();
                    ans.insert(temp);
                } else if (temp.size() == ans.begin()->size()) {
                    ans.insert(temp);
                }
            }

            return;
        }

        int newCnt = cnt;

        if (s[i] == '(') {
            newCnt++;
        } else if (s[i] == ')') {
            newCnt--;
        }

        if (cnt < 0) {
            return;
        }

        temp.push_back(s[i]);
        solve(i + 1, temp, ans, s, newCnt);
        temp.pop_back();
        solve(i + 1, temp, ans, s, cnt);
    }

    bool isValid(string& s) {
        int cnt = 0;

        for (char c : s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                cnt--;

                if (cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }
};