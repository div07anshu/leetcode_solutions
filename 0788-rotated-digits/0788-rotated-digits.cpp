class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[1] = 1, mp[0] = 0, mp[8] = 8;
        mp[2] = 5, mp[5] = 2;
        mp[6] = 9, mp[9] = 6;

        for (int i = 1; i <= n; i++) {
            bool cond = true;
            int num = i;
            int fin = 0;
            int mul = 1;
            while (num > 0) {
                int a = num % 10;

                if (!mp.count(a)) {
                    cond = false;
                    break;
                }

                fin += mul * mp[a];
                mul = mul * 10;
                num = num / 10;
            }

            if (cond && (fin != i)) {
                cnt++;
            }
        }

        return cnt;
    }
};