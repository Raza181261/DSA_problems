class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = NULL;
        int count = 0;

        for(int i = 0; i<n; i++){
            if(maj == nums[i]){
                count++;
            } else if(count == 0){
                maj = nums[i];
            }else {
                count--;
            }
        }
        return maj;
    }
};