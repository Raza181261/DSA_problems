class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans  = nums[0];
        for(int i = 1; i<nums.size(); i++){
            ans = ans ^ nums[i]; // 2 ^ 2
        //  ans = 10 ^ 10 ==> 00
        //  ans  = 0
        }
        return ans;
    }
};