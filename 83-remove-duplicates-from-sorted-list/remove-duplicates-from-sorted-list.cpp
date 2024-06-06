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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head;
        ListNode* temp = prev->next;

        while(temp != nullptr){
            if(temp->val == prev->val){
                temp = temp->next;
                continue;
            }
            prev->next = temp;
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        return head;
    }
};