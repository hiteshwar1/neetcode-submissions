/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> oldtocopy;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            oldtocopy[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            Node* copy = oldtocopy[curr];
            copy->next = oldtocopy[curr->next];
            copy->random = oldtocopy[curr->random];
            curr = curr->next;
        }
        return oldtocopy[head];
    }
};
