class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxe = *max_element(nums.begin(), nums.end());
        vector<int> res;
        unordered_map<int, int> mp;
        unordered_map<int, long long> gcdcnt;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    mp[j]++;
                    if (num / j != j) {
                        mp[num / j]++;
                    }
                }
            }
        }

        for (int g = maxe; g >= 1; g--) {
            long long cnt = mp[g];
            long long cntfreq = (1LL * cnt * (cnt - 1)) / 2;

            for (int st = 2 * g; st <= maxe; st += g) {
                if (mp[st]) {
                    cntfreq -= gcdcnt[st];
                }
            }

            gcdcnt[g] = cntfreq;
        }

        vector<long long> arr(maxe + 1, 0);

        for (auto it : gcdcnt) {
            int num = it.first;
            long long freq = it.second;
            arr[num] = freq;
        }

        for (int i = 2; i <= maxe; i++) {
            arr[i] = arr[i - 1] + arr[i];
        }

        for (auto idx : queries) {
            int l = 1, h = maxe;
            int ans = maxe;

            while (l <= h) {
                int mid = l + (h - l) / 2;

                if (arr[mid] >= idx + 1) {
                    ans = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            res.push_back(ans);
        }

        return res;
    }
};