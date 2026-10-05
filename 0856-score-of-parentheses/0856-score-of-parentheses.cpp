class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int score = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(score);
                score = 0;
            } else {
                if (s[i - 1] == '(') {
                    score = st.top() + 1;
                } else {
                    score = 2 * score + st.top();
                }

                st.pop();
            }
        }

        return score;
    }
};