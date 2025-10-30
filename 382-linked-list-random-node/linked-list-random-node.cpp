/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0)); // seed for randomness
    }
    
    int getRandom() {
        ListNode* curr = head;
        int result = curr->val;
        int n = 1;
        
        while (curr != nullptr) {
            if (rand() % n == 0) {
                result = curr->val;
            }
            curr = curr->next;
            n++;
        }
        return result;
    }
};
