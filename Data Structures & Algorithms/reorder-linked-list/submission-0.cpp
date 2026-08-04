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
        ListNode* slow = head;
        ListNode* fast = head;

        // divide the list into two using slow and fast pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }


        // reverese the second half
        ListNode dummy(0);
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = tmp;
        }
        ListNode* rev = dummy.next;

        // Merge the two lists, starting with the left one
        curr = head;
        while (curr && rev) {
            ListNode* nxt = curr->next;
            ListNode* rnxt = rev->next;
            curr->next = rev;
            rev->next = nxt;
            curr = nxt;
            rev = rnxt;
        }
    }
};
