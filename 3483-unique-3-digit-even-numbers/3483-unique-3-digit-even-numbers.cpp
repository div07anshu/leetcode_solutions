class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int cnt = 0;
        unordered_set<int> st;
        // i -> start , j -> mid , k -> end ;

        for (int i = 0; i < n; i++) {
            if (digits[i] % 2) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != i && k != j && k != i && digits[k]) {
                        int num = digits[k] * 100 + digits[j] * 10 + digits[i];
                        st.insert(num);
                    }
                }
            }
        }

        return st.size();
    }
};