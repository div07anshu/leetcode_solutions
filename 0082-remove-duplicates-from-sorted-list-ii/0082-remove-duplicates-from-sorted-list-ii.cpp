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
    ListNode* deleteDuplicates(ListNode* head) {
        Node* prev = nullptr;
        Node* temp = head;
        set<int> st;

        while (temp != nullptr) {
            if (prev == nullptr) {
                prev = temp;
                temp = temp->next;
                continue;
            }

            Node* front = temp->next;

            if (temp->val == prev->val) {
                prev->next = front;
                st.insert(temp->val);
                temp = front;
            } else {
                prev = temp;
                temp = front;
            }
        }

        Node* mover = head;
        prev = nullptr;
        while (mover != nullptr) {
            Node* front = mover->next;
            if (st.count(mover->val)) {
                if (prev == nullptr) {
                    head = head->next;
                    mover = head;
                } else {
                    prev->next = front;
                    mover = front;
                }
            } else {
                prev = mover;
                mover = front;
            }
        }

        return head;
    }
};