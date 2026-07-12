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
    ListNode* mergeLists(ListNode* x, ListNode* y) {
        ListNode* res = new ListNode();
        ListNode* head = res;
        while (x && y) {
            if (x->val < y->val) {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> q;
        for (int i = 0; i < lists.size(); i++) {
            if (q.empty()) {
                q.push(lists[i]);
            } else {
                ListNode* newList = mergeLists(q.top(), lists[i]);
                q.pop();
                q.push(newList);
            }
        }
        return q.top();
    }
};
