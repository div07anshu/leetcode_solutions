class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minn = INT_MAX, maxn = INT_MIN;
        int mini = -1, maxi = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxn) {
                maxn = nums[i];
                maxi = i;
            }

            if (nums[i] < minn) {
                minn = nums[i];
                mini = i;
            }
        }

        int c1, c2, c3;
        if (mini > maxi) {
            swap(mini, maxi);
        }

        c1 = mini + 1 + n - maxi; // one from front other from back
        c2 = maxi + 1;            // both from the front
        c3 = n - mini;            // both from back

        return min({c1, c2, c3});
    }
};