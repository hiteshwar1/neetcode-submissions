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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        for (auto node : lists) {
            if(node) q.push(node);
        }
        ListNode* res = new ListNode();
        ListNode* head = res;
        while (!q.empty()) {
            auto node = q.top();
            auto next = node->next;
            q.pop();
            res->next = node;
            if (next) {
                q.push(next);
            }
            res = res->next;
        }
        return head->next;
    }
};
