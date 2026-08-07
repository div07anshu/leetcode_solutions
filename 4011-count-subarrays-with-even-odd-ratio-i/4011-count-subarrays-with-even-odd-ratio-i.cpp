class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        double req = (a * 1.0) / b;
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int cnte = 0, cnto = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    cnte++;
                } else {
                    cnto++;
                }

                double ratio = -1;
                if (cnto > 0) {
                    ratio = (cnte * 1.0) / cnto;
                }

                if (ratio <= req && ratio != -1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};