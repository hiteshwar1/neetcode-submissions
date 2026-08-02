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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* midNode(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* x = head;
        ListNode* mid = midNode(head);
        ListNode* y = mid->next;
        mid->next = nullptr;
        y = reverseList(y);
        while (x && y) {
            ListNode* nextX = x->next;
            ListNode* nextY = y->next;
            x->next = y;
            y->next = nextX;
            x = nextX;
            y = nextY;
        }
    }
};
