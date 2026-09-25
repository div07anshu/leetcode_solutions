class Solution {
public:
    int n;
    string s;
    int idx = 0;

    set<string> performUnion() {
        set<string> result;

        while (true) {
            set<string> temp = performConcat();
            result.insert(begin(temp), end(temp));

            if (idx < n && s[idx] == ',')
                idx++;
            else
                break;
        }

        return result;
    }

    set<string> performConcat() {
        set<string> result = {""};

        while (idx < n && (s[idx] == '{' || isalpha(s[idx]))) {
            set<string> temp = getUnite();

            set<string> concat;

            for (const string& left : result) {
                for (const string& right : temp) {
                    concat.insert(left + right);
                }
            }

            result = concat;
        }

        return result;
    }

    set<string> getUnite() {
        set<string> result;

        if (s[idx] == '{') {
            idx++;
            result = performUnion();
        } else {
            result = {string(1, s[idx])};
        }

        idx++;
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        n = expression.size();

        set<string> st = performUnion();
        vector<string> result(st.begin(), st.end());
        return result;
    }
};