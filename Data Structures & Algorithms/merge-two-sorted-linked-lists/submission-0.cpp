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
    ListNode* merge(ListNode* x, ListNode* y) {
        ListNode* res = new ListNode();
        ListNode* head = res;
        while (x && y) {
            if (x->val <= y->val) {
                res->next = x;
                x = x->next;
            } else {
                res->next = y;
                y = y->next;
            }
            res = res->next;
        }
        if (x) res->next = x;
        if (y) res->next = y;
        return head->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { return merge(list1, list2); }
};
