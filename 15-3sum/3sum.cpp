class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
           if(i>0 && nums[i] == nums[i-1])
           continue;
       

        unordered_map<int, int>H_map;
        int target = -nums[i];

        for(int j = i+1; j<n; j++){
           int complement = target - nums[j];

           if(H_map.find(complement) != H_map.end()){
            result.push_back({nums[i], nums[j], complement});

            while(j+1<n && nums[j] == nums[j+1]){
                j++;

            }
           }
           H_map[nums[j]] == j;
        }
    }
return result;
    }
    
};