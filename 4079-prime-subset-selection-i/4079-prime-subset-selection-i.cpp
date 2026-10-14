class Solution {
public:
    vector<bool> Prime(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = false, prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == false) {
                continue;
            }

            for (int k = 2 * i; k <= n; k += i) {
                prime[k] = false;
            }
        }

        return prime;
    }

    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime = Prime(n);
        vector<int> ans;
        int i = 0;
        int sum = 0;

        while (i <= n && sum <= s) {
            if (sum + i > s)
                break;
            if (isPrime[i] && sum + i <= s) {
                sum += i;
                ans.push_back(i);
            }

            i++;
        }

        return ans;
    }
};