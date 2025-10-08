class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;  // already valid if <=2 elements

        int j = 2;  // position where the next valid element should go

        for (int i = 2; i < n; i++) {
            // Only copy nums[i] if it's not the same as nums[j-2]
            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;  // length of modified array
    }
};
