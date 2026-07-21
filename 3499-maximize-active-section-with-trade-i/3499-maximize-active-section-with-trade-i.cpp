class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";

        int n = s.size();
        vector<int> arr;
        int cnt = 0;
        int ones = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
            } else {
                ones++;
                if (cnt) {
                    arr.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        
        ones -= 2;

        int maxs = 0;
        for (int i = 1; i < arr.size(); i++) {
            maxs = max(maxs, arr[i] + arr[i - 1]);
        }

        return ones + maxs;
    }
};