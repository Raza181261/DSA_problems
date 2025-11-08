class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = nums[0];
        int min_prod = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] < 0){
                swap(max_prod, min_prod);
            }
            max_prod = max(nums[i], nums[i] * max_prod);
            min_prod = min(nums[i], nums[i] * min_prod);

            ans = max(ans,max_prod);
        }
        return ans;
    }
};