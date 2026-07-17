class LRUCache {
    class Node {
       public:
        int key, val;
        Node *next = nullptr, *prev = nullptr;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    unordered_map<int, Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }

    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            int res = m[key]->val;
            removeNode(m[key]);
            addNode(m[key]);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;
            removeNode(node);
            addNode(node);
            return;
        }
        if (m.size() == capacity) {
            Node* lru = tail->prev;
            removeNode(lru);
            m.erase(lru->key);
        }
        Node* node = new Node(key, value);
        m[key] = node;
        addNode(node);
    }
};
