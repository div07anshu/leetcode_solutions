
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            busy;

        int n = servers.size();
        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < n; i++)
            free.push({servers[i], i});

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            if (free.empty())
                time = busy.top().first;

            while (!busy.empty() && busy.top().first <= time) {
                auto [t, idx] = busy.top();
                busy.pop();
                free.push({servers[idx], idx});
            }

            auto [weight, idx] = free.top();
            free.pop();

            ans.push_back(idx);
            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};
