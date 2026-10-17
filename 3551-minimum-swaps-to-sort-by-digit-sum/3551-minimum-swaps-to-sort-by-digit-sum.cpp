class Solution {
public:
    int minSwaps(vector<int>& nums) {
        auto lambda = [&](int num1, int num2) {
            int dig1 = dig(num1);
            int dig2 = dig(num2);

            if (dig1 != dig2) {
                return dig1 < dig2;
            }

            return num1 < num2;
        };

        vector<int> arr = nums;
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end(), lambda);

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == arr[i])
                continue;

            int original_idx = mp[arr[i]];
            swap(nums[i], nums[original_idx]);
            mp[nums[original_idx]] = original_idx;
            mp[nums[i]] = i;
            cnt++;
        }

        return cnt;
    }

    int dig(int x) {
        int sum = 0;

        while (x != 0) {
            sum += x % 10;
            x = x / 10;
        }

        return sum;
    }
};