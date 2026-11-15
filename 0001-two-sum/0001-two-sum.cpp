class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); i++) {
            data.push_back({nums[i], i});
        }

        sort(data.begin(), data.end());
        int i = 0, j = data.size() - 1;
        while (i < j) {
            if (data[i].first + data[j].first == target) {
                return {data[i].second, data[j].second};
            }

            else if (data[i].first + data[j].first > target) {
                j--;
            } else {
                i++;
            }
        }

        return {} ;
    }
};