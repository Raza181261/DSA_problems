class Solution {
public:
     vector<vector<int>> result;
     void getAllSubset(vector<int>& nums,vector<int>& temp, int i, vector<vector<int>>&  result){
        if(i == nums.size()){
            result.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[i]);
        getAllSubset(nums,temp,i+1,result);

        temp.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        
        //exclude
        getAllSubset(nums,temp,idx,result);


     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;

        getAllSubset(nums,temp,0,result);

        return result;
    }
};