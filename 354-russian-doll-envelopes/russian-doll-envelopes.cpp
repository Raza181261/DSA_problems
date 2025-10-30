class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        
        // Sort by width ascending; if width same, sort height descending
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        
        // Extract heights
        vector<int> heights;
        for (auto& e : envelopes) heights.push_back(e[1]);
        
        // Find LIS in heights
        vector<int> dp;
        for (int h : heights) {
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) dp.push_back(h);
            else *it = h;
        }
        
        return dp.size();
    }
};
