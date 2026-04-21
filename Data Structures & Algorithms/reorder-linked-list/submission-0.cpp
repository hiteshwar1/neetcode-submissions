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
    ListNode* midNode(ListNode* head){
        ListNode* slow = head,*fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *first = head;
        ListNode *second = midNode(head)->next;
        midNode(head)->next = NULL;
        second = reverseList(second);
        while(second){
            ListNode* x = first->next;
            ListNode* y = second->next;
            first->next = second;
            second->next = x;
            first = x;
            second = y;
        }
    }
};
