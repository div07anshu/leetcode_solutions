class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);
        vector<int> hash(26, 0);
        stack<int> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a']) {
                continue;
            }

            while (!st.empty() && st.top() > s[i] && last[st.top() - 'a'] > i) {
                hash[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(s[i]);
            hash[s[i] - 'a'] = 1;
        }

        while (!st.empty()) {
            char top = st.top();
            ans = top + ans;
            st.pop();
        }

        return ans;
    }
};