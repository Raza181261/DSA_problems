class Solution {
public:
      bool containsNearbyDuplicate(vector<int>& nums, int k){
      unordered_map<int, int> num_map; // map to store (element, index) pairs

        for(int i = 0; i < nums.size(); i++){
        // Check if the current element exists in the map
        if (num_map.find(nums[i]) != num_map.end()) {
            // Calculate the distance between current index and the stored index
            int distance = i - num_map[nums[i]];
            // If the distance is less than or equal to k, return true
            if (distance <= k) {
                return true;
            }
        }
        // Update the index of the current element in the map
        num_map[nums[i]] = i;
    }

    return false;
}
};