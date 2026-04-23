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

class Solution {
   public:
    ListNode* midLL(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* revLL(ListNode* head) {
        ListNode *curr = head, *next = nullptr, *prev = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* x = head;
        ListNode* mid = midLL(x);
        ListNode* y = mid->next;
        mid->next = nullptr;
        y = revLL(y);
        while (x && y) {
            ListNode* nextx = x->next;
            ListNode* nexty = y->next;
            x->next = y;
            y->next = nextx;
            x = nextx;
            y = nexty;
        }
    }
};
