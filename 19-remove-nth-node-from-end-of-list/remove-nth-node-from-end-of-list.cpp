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
    int getLengthOfLinkList(ListNode* head){
        int length = 0;
        while(head != NULL){
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //step1
        int L = getLengthOfLinkList(head);

        //step2 check corner case
        if(n == L){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }

        //step3
        int travel_front = L-n;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(travel_front--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete(temp);
        return head;

    }
};