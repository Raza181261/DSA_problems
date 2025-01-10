class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operation = 0;
        unordered_set<int>st(begin(nums),end(nums));
        for(int num:st){
            if(num == k)
              continue;
            if(num < k)
            return -1;
            operation += 1;
        }
        return operation;
    }
};