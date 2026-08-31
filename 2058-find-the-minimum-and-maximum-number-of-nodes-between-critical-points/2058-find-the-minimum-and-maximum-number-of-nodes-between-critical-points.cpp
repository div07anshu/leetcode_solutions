/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
using Node = ListNode;
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        Node* prev = nullptr;
        Node* temp = head;

        vector<pair<int, int>> arr;
        int idx = 1;

        while (temp->next != nullptr) {
            Node* front = temp->next;

            if (prev == nullptr) {
                prev = temp;
                temp = temp->next;
                idx++;
                continue;
            }

            int pval = prev->val;
            int fval = front->val;
            int val = temp->val;

            if (val > pval && val > fval) {
                arr.push_back({val, idx});
            } else if (val < pval && val < fval) {
                arr.push_back({val, idx});
            }

            prev = temp;
            temp = temp->next;
            idx++;
        }

        int n = arr.size();
        if (n < 2) {
            return {-1, -1};
        }

        int mind = INT_MAX;
        int maxd = arr[n - 1].second - arr[0].second;

        for (int i = 1; i < n; i++) {
            mind = min(mind, arr[i].second - arr[i - 1].second);
        }

        return {mind, maxd};
    }
};