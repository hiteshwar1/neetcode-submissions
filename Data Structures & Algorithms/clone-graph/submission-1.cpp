/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> oldtonew;
        oldtonew[node] = new Node(node->val);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto i : curr->neighbors) {
                if (oldtonew.find(i) == oldtonew.end()) {
                    oldtonew[i] = new Node(i->val);
                    q.push(i);
                }
                oldtonew[curr]->neighbors.push_back(oldtonew[i]);
            }
        }
        return oldtonew[node];
    }
};
