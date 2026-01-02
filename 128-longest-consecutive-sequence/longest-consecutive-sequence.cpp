class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> numSet(nums.begin(), nums.end());
        // int longest = 0;

        // for(int num:numSet){
        //     if(numSet.find(num-1) == numSet.end()){ // this line return true if number not present 
        //         int currNum = num;
        //         int streak = 1;

        //         while(numSet.find(currNum+1) != numSet.end()){
        //             currNum += 1;
        //             streak += 1;
        //         }
        //         longest = max(longest,streak);
        //     }

        // }
        // return longest;
        
         int currLength = 1;
         int maxLength = 1;
         int n = nums.size();
         if(n == 0){
            return 0;
         } 
         sort(begin(nums), end(nums));
         for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){ //it will check duplicates
                continue;
            }else if(nums[i] == nums[i-1]+1){ // it will check consecutive elements;
                currLength += 1;
            }else{
                currLength = 1;
            }

            maxLength = max(currLength, maxLength);
         }
         return maxLength;
    }
};