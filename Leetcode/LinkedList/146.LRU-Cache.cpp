class Node {
public: 
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int _key, int _val) {
        val = _val;
        key = _key;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;
 
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
       Node* prev = right->prev;

       right->prev = node;
       prev->next = node;

       node->prev = prev;
       node->next = right; 
    }

    int get(int key) {
        if (mp.count(key)) {
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            remove(mp[key]);
        }

        mp[key] = new Node(key, value);
        insert(mp[key]);

        if (mp.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */