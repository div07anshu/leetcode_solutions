class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reserved) {
        set<int> st;
        map<pair<int, int>, int> mp;

        for (auto k : reserved) {
            st.insert(k[0]);
            mp[{k[0], k[1]}] = 1;
        }

        int cntgrp = 0;

        for (auto x : st) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int j = 2; j <= 5; j++) {
                if (mp.count({x, j})) {
                    left = false;
                    break;
                }
            }

            for (int j = 4; j <= 7; j++) {
                if (mp.count({x, j})) {
                    middle = false;
                    break;
                }
            }

            for (int j = 6; j <= 9; j++) {
                if (mp.count({x, j})) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                cntgrp += 2;
            } else if (left || middle || right) {
                cntgrp++;
            }
        }

        cntgrp += (n - st.size()) * 2;

        return cntgrp;
    }
};