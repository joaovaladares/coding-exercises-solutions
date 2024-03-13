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
    void reorderList(ListNode* head) {
        if (head->next == nullptr) return;

        ListNode *slow = head, *fast = head->next;

        // find middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse second half
        ListNode* second = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while (second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        //merge two halfs
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while (l2 != nullptr && l1 != nullptr) {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;

            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};