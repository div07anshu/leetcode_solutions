using vi = vector<int>;
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            vector<int> temp = nums;
            bool ok = true;

            for (int start = 0; start <= n - k; start += k) {
                vector<int> arr(nums.begin() + start, nums.begin() + start + k);

                if (!check(arr)) {
                    ok = false;
                    break;
                }

                sort(temp.begin() + start, temp.begin() + start + k);
            }

            if (ok && temp == sorted) {
                sum += k;
            }
        }

        return sum;
    }

    bool check(vi& arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[(i + 1) % n]) {
                cnt++;
            }
        }

        return cnt <= 1;
    }
};