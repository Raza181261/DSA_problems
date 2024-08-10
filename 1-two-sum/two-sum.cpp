class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //    unordered_map<int, int> num_map; // map to store (element, index) pairs

    //     for (int i = 0; i < nums.size(); ++i) {
    //         int complement = target - nums[i];
    //         if (num_map.find(complement) != num_map.end()) {
    //             // If the complement exists in the map, return the pair of indices
    //             return { num_map[complement], i };
    //         }
    //         // Add the current number to the map with its index
    //         num_map[nums[i]] = i;
    //     }

    //     // If no solution is found, return an empty vector
    //     return {};
    // }

    unordered_map <int, int> mp;
    for(int i =0; i<nums.size(); i++){
        int subtraction  = target - nums[i];
        if(mp.find(subtraction) != mp.end()){
            return {mp[subtraction], i};
        }
        mp[nums[i]] = i ;
    }
    return {};
}
};