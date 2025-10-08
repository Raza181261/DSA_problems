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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        // Dummy node to handle edge cases (duplicates at head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;   // node before the current sequence
        ListNode* curr = head;

        while (curr) {
            // Detect duplicates
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                // Skip all nodes with this value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                prev->next = curr; // remove duplicates
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
