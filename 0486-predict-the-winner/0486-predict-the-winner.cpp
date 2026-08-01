class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int player1 = solve(0, n - 1, nums);
        int player2 = tot - player1;

        return player1 >= player2;
    }

    int solve(int i, int j, vector<int>& nums) {

        if (i > j) {
            return 0;
        }

        if (i == j) {
            return nums[i];
        }

        int t1 =
            nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));

        int t2 =
            nums[j] + min(solve(i, j - 2, nums), solve(i + 1, j - 1, nums));

        return max(t1, t2);
    }
};