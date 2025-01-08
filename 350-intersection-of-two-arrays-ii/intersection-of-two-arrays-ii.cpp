class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>st1;

        for(int n : nums1){
            st1[n]++;
        }

        vector<int>result;

        for(int num : nums2){
           if(st1[num] > 0){
            st1[num]--;
            result.push_back(num);
           }

            }
        
        return result;

        
    }
};