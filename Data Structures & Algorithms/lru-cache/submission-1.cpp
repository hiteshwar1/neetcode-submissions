class LRUCache {
    class Node {
       public:
        int key, value;
        Node *next, *prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    int capacity;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        m = unordered_map<int, Node*>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            removeNode(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->value = value;
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
