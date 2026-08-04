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
        ListNode* dummy = new ListNode(0);
        ListNode* left = head;
        ListNode* right = head;

        for (int i = 0; i < n; i++) {
            right = right->next;
        }

        ListNode* start = dummy;
        while (right) {
            start->next = left;
            start = start->next;
            left = left->next;
            right = right->next;
        }

        start->next = left->next;

        return dummy->next;
    }
};
