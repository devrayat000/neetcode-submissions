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
        // define two pointers
        ListNode* pivot = head;
        ListNode* last = head;
        // give the last pointer a head start
        for (int i = 0; i < n; i++) {
            last = last->next;
        }

        // define a dummy list
        ListNode* dummy = new ListNode(0);
        // define the previous element of the pivot
        ListNode* start = dummy;
        while (last) {
            start->next = pivot;
            start = start->next;
            pivot = pivot->next;
            last = last->next;
        }
        // connect the previous element to the pivot's next
        start->next = pivot->next;

        return dummy->next;
    }
};
