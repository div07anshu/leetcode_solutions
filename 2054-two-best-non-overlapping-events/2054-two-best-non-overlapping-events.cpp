class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxsum = -1;
        vector<int> maxsuffix(n);
        sort(events.begin(), events.end());
        maxsuffix[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            maxsuffix[i] = max(events[i][2], maxsuffix[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            int check = events[i][1];
            int idx = -1;

            int low = i + 1, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (events[mid][0] > check) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (idx != -1) {
                maxsum = max(maxsum, events[i][2] + maxsuffix[idx]);
            }

            maxsum = max(maxsum, events[i][2]);
        }

        return maxsum;
    }
};