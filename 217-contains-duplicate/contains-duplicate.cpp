class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       sort(begin(nums), end(nums));
       for(int i = 0; i<nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
       }
        return false;

        // unordered_map<int,int>count;
        // for(int num:nums){
        //     if(count[num] > 0){
        //          return true;
        //     }
        //     count[num]++;
        // }
        // return false;
    }
};