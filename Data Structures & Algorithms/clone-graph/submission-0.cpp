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
        unordered_map<Node*, Node*> nodemap;
        nodemap[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            Node* currnode = q.front();
            q.pop();
            for (auto i : currnode->neighbors) {
                if (nodemap.find(i) == nodemap.end()) {
                    nodemap[i] = new Node(i->val);
                    q.push(i);
                }
                nodemap[currnode]->neighbors.push_back(nodemap[i]);
            }
        }
        return nodemap[node];
    }
};
