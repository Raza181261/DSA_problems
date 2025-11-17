class Solution {
public:
     int S;
     int solve(vector<int>& nums, int target, int i, int currSum, vector<vector<int>>& t){
        if(i == nums.size()){
            if(currSum == target){
                return 1;
            } else {
                return 0;
            }
        }
        if(t[i][currSum+S] != -1){
            return t[i][currSum+S];
        }

       

        int plus  = solve(nums,target, i+1, currSum + nums[i],t);
        int minus = solve(nums,target, i+1, currSum - nums[i], t);

        return t[i][currSum+S] = plus + minus;
     }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        S = accumulate(begin(nums), end(nums) ,0);
        vector<vector<int>> t(n+1, vector<int>(2*S+1, -1));

        return solve(nums,target,0,0,t);
    }
};