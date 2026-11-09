class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& l) {
        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> cnt(k, 0);

        for (int i = 0; i < a.size(); i++) {
            while (!pq.empty() && pq.top().first <= a[i]) {
                st.insert(pq.top().second);
                pq.pop();
            }

            if (st.empty()) {
                continue;
            }

            int x = i % k;
            auto it = st.lower_bound(x);

            if (it == st.end()) {
                it = st.begin();
            }

            int s = *it;
            st.erase(it);
            pq.push({a[i] + l[i], s});
            cnt[s]++;
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};