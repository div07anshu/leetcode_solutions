using vs = vector<string>;
class Solution {
public:
    int dp[1001][1001];
    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof(dp));
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });

        return solve(0, -1, words);
    }

    int solve(int i, int prev, vs& words) {
        if (i >= words.size()) {
            return 0;
        }

        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int skip = solve(i + 1, prev, words);
        int take = 0;

        if (prev == -1 || isPred(words[prev], words[i])) {
            take = 1 + solve(i + 1, i, words);
        }

        return dp[i][prev + 1] = max(skip, take);
    }

    bool isPred(string& prev, string& curr) {
        if (prev.size() != curr.size() - 1) {
            return false;
        }

        int f = 0, s = 0;

        while (f < prev.size() && s < curr.size()) {
            if (prev[f] == curr[s]) {
                f++;
            }
            s++;
        }

        return f == prev.size();
    }
};