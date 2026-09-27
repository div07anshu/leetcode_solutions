class Solution {
public:
    string reverseParentheses(string s) {
        queue<pair<int, int>> q;
        stack<int> temp;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                temp.push(i);
            } else if (s[i] == ')') {
                int l = temp.top();
                temp.pop();
                q.push({l, i});
            }
        }

        while (!q.empty()) {
            auto [l, r] = q.front();
            q.pop();
            reverse(s.begin() + l + 1, s.begin() + r);
        }

        string ans;

        for (auto x : s) {
            if (x != '(' && x != ')') {
                ans += x;
            }
        }

        return ans;
    }
};