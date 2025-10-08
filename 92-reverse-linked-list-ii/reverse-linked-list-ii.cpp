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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 1: move prev to the node before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: reverse sublist from left to right
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* tail = curr; // will become tail of the reversed section

        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }

        // Step 3: reconnect tail to the remaining list
        tail->next = curr;

        return dummy->next;
    }
};
