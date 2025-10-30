class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) return false;

        set<long long> window;  // balanced BST to maintain the sliding window
        for (int i = 0; i < nums.size(); ++i) {
            long long val = nums[i];

            // Find the smallest number >= val - valueDiff
            auto it = window.lower_bound(val - valueDiff);

            // Check if within valueDiff range
            if (it != window.end() && *it - val <= valueDiff)
                return true;

            window.insert(val);

            // Maintain window size (indexDiff constraint)
            if (i >= indexDiff)
                window.erase(nums[i - indexDiff]);
        }
        return false;
    }
};
