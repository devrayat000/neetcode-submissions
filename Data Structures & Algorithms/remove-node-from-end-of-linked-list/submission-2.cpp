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
        // define a dummy list
        ListNode* dummy = new ListNode(0, head);
        // define two pointers
        ListNode* pivot = dummy;
        ListNode* last = head;
        // give the last pointer a head start
        for (int i = 0; i < n; i++) {
            last = last->next;
        }

        while (last) {
            pivot = pivot->next;
            last = last->next;
        }
        // connect the previous element to the pivot's next
        pivot->next = pivot->next->next;

        return dummy->next;
    }
};
