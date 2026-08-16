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
    ListNode* reverseBetween(Node* head, int l, int r) {

        if (head == nullptr || head->next == nullptr || l == r) {
            return head;
        }

        Node* left = head;
        Node *leftprev = nullptr, *rightfront = head->next;
        int cntl = 1, cntr = 1;

        while (cntl < l) {
            leftprev = left;
            left = left->next;
            cntl++;
        }

        while (cntr < r) {
            rightfront = rightfront->next;
            cntr++;
        }

        Node* temp = left;
        Node* prev = nullptr;
        while (temp != rightfront) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        if (leftprev != nullptr) {
            leftprev->next = prev;
        } else {
            head = prev;
        }

        left->next = rightfront;

        return head;
    }
};