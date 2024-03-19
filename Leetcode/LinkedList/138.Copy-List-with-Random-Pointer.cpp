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
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* h = head;

        while(h) {
            Node* newNode = new Node(h->val);
            mp[h] = newNode;
            h = h->next;
        }

        h = head;

        while (h) {
            Node* newNode = mp[h];
            newNode->next = mp[h->next];
            newNode->random = mp[h->random];
            h = h->next;
        }

        return mp[head];
    }
};