using vvi = vector<vector<int>>;
using vi = vector<int>;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> table;
    int binarysearch(vector<pair<int, int>>& arr, int tar) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int res = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m].first <= tar) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
    vector<int> pathExistenceQueries(int n, vi& nums, int md, vvi& q) {
        vector<pair<int, int>> arr(n);
        vector<int> result;

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());
        vector<int> nti(n);

        for (int i = 0; i < n; i++) {
            int node = arr[i].second;
            nti[node] = i;
        }

        rows = n, cols = log2(n) + 1;
        table.resize(rows, vector<int>(cols, 0));

        // fill zero column first ;

        for (int node = 0; node < n; node++) {
            int farthestjump = binarysearch(arr, arr[node].first + md);
            table[node][0] = farthestjump;
        }

        // now fill the remaining columns ;

        for (int j = 1; j < cols; j++) {
            for (int i = 0; i < n; i++) {
                table[i][j] = table[table[i][j - 1]][j - 1];
            }
        }

        for (auto& query : q) {
            int u = query[0], v = query[1];
            int a = nti[u];
            int b = nti[v];

            if (a == b) {
                result.push_back(0);
                continue;
            }

            if (a > b) {
                swap(a, b);
            }

            int curr = a, jumps = 0;

            for (int j = cols - 1; j >= 0; j--) {
                if (table[curr][j] < b) {
                    curr = table[curr][j];
                    jumps += (1 << j); // 2^j ;
                }
            }

            if (table[curr][0] >= b) {
                result.push_back(jumps + 1);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};