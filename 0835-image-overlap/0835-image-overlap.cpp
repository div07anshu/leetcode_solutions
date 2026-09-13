class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxl = 0;

        for (int l = -(n - 1); l <= n - 1; l++) {
            for (int d = -(n - 1); d <= n - 1; d++) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int ni = i + l;
                        int nj = j + d;

                        if (ni >= n || nj >= n) {
                            continue;
                        }

                        if (ni < 0 || nj < 0) {
                            continue;
                        }

                        if (img1[i][j] == 1 && img2[i + l][j + d] == 1) {
                            cnt++;
                        }
                    }
                }

                maxl = max(cnt, maxl);
            }
        }

        return maxl;
    }
};