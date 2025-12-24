class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // using map
        // unordered_map<int,int>mp;
        // for(int num:nums){
        //     if(mp[num] > 0){
        //         return true;
        //     } mp[num]++;
        // }
        // return false;

        //solve using sorting
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
            return false;
    }
};