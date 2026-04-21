class LRUCache {
    class Node{
        public:
        Node* next = NULL;
        Node* prev = NULL;
        int val;
        int key;
        Node(int key,int val){
            this->key = key;
            this->val = val;
        }
    };
public:
    unordered_map<int,Node*> m;
    int size ;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void insert(Node* node){
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            remove(node);
            insert(node);
            m[key] = head->next;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            remove(node);
        }
        else if(m.size()==size){ 
            Node* node = tail->prev;
            remove(node);
            m.erase(node->key);
        }
        Node* newNode = new Node(key,value);
        insert(newNode);
        m[key] = head->next;
    }
};
