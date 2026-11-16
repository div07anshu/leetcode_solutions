class Solution {
public:
    string digitSum(string s, int k) {
        string str = "";

        while (s.size() > k) {
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int digSum = 0;
                for (int j = i; j < n && j < i + k; j++) {
                    digSum += s[j] - '0';
                }

                str += to_string(digSum);
            }

            s = str;
            str = "";
        }

        return s;
    }
};