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
    int numComponents(ListNode* head, vector<int>& nums) {
        int tolCount = 0;
        unordered_set<int> hashset(nums.begin(), nums.end());
        ListNode* curr = head;

        while(curr != nullptr){
            if(hashset.count(curr->val) && 
            (curr -> next == nullptr || !hashset.count(curr->next->val))){
            tolCount++;
            }
            curr = curr->next;
        }
        return tolCount;

    }
};