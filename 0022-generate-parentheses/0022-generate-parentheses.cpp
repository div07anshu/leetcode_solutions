class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string temp;
        solve(temp, n, n);
        return result;
    }

    void solve(string& temp, int l, int r) {
        if (l == 0 && r == 0) {
            result.push_back(temp);
            return;
        }

        if (l > r || l < 0 || r < 0) {
            return;
        }

        temp.push_back('(');
        solve(temp, l - 1, r);
        temp.pop_back();

        temp.push_back(')');
        solve(temp, l, r - 1);
        temp.pop_back();
    }
};