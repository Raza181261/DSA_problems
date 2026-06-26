class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int curr_length = 1;
        int max_length = 1;
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        sort(begin(nums), end(nums));

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                continue;
            } else if(nums[i] == nums[i-1]+1){
                curr_length += 1;
            } else {
                curr_length = 1;
            }

            max_length = max(max_length, curr_length);
        }

        return max_length;
    }
};