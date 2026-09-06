class Solution {
public:
    int countGroups(vector<int>& dis, vector<int>& speed, int distance) {
        int n = speed.size();
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (dis[i + 1] - dis[i] <= distance || speed[i] > speed[i + 1]) {
                speed[i] = speed[i + 1];
            } else {
                ans++;
            }
        }

        return ans;
    }
};