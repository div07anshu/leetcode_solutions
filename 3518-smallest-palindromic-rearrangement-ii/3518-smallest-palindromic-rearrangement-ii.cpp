class Solution {
public:
    string smallestPalindrome(string s, int k) {
        string mid = "";
        int n = s.size();
        int half = n / 2;

        if (n % 2 != 0) {
            mid.push_back(s[n / 2]);
        }

        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2) {
                continue; // mid char already counted ;
            }
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            count[i] = count[i] / 2;
        }

        string halfResult = "";
        bool isplaced = false;

        for (int len = 0; len < half; len++) {
            for (int i = 0; i < 26; i++) {
                if (count[i]) {
                    count[i]--;
                    // count number of ways ;

                    long long ways = 1;
                    int letters = 0;

                    for (auto ch : count) {
                        letters += ch;
                    }

                    for (int c = 0; c < 26; c++) {
                        if (count[c] > 0) {
                            ways *= ncr(letters, count[c], k);
                            letters -= count[c];
                        }

                        if (ways >= k) {
                            break;
                        }
                    }

                    if (ways >= k) {
                        halfResult.push_back(i + 'a');
                        isplaced = true;
                        break;
                    }

                    k -= ways;
                    count[i] += 1;
                }
            }

            if (!isplaced) {
                return "";
            }
        }

        string rev = halfResult;
        reverse(rev.begin(), rev.end());

        return halfResult + mid + rev;
    }

    long long ncr(int n, int r, int k) {
        r = min(r, n - r);
        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            if (result >= k) {
                return k;
            }
        }

        return result;
    }
};