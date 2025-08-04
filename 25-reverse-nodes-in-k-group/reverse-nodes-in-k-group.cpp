class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // check if k node exits
        while (count < k) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
            count++;
        }

        // recursively call rest part of LinkedList
        ListNode* prevNode = reverseKGroup(temp, k);

            // reverse current part
            temp = head;
        count = 0;

        while (count < k) {
            ListNode* Next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = Next;

            count++;
        }

        return prevNode;
    }
};