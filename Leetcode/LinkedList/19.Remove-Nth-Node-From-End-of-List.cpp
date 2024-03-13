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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *delayPointer = head, *curr = head;
        int count = 0;
        
        while(count < n) {
            curr = curr->next;
            count++; 
        }
        
        if (!curr) return head->next;

        while(curr->next) {
            curr = curr->next;
            delayPointer = delayPointer->next;
        }

        delayPointer->next = delayPointer->next->next;

        return head;
    }
};
