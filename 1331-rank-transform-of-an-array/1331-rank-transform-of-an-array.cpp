class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;
        vector<int> res;
        int n = arr.size();

        sort(a.begin(), a.end());
        map<int, int> mp;
        int rank = 1;

        for (int i = 0; i < n; i++) {
            int num = a[i];
            if (mp.find(num) == mp.end()) {
                mp[num] = rank;
                rank++;
            }
        }

        for (int i = 0; i < n; i++) {
            res.push_back(mp[arr[i]]);
        }

        return res;
    }
};