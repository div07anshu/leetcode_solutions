class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> res;

        for (int len = 2; len <= 9; len++) {
            int i = 0;
            while (i + len <= 9) {
                string str = s.substr(i, len);
                int num = stoi(str);
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
                i++;
            }
        }

        return res;
    }
};