class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If middle element is less than next, peak is on the right
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else // else peak is on the left or at mid
                right = mid;
        }
        
        return left; // left == right is the peak index
    }
};
