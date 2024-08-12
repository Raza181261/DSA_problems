class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int subArr = nums[0];
        int curr = 0;

        for(int i = 0; i<nums.size(); i++){
            if(curr < 0)
             curr = 0;
             curr += nums[i]; 
             subArr = max(subArr, curr);
        }
        return subArr;
    }
};