class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for (auto& b : buildings) {
            // start event: negative height to indicate building start
            events.push_back({b[0], -b[2]});
            // end event: positive height
            events.push_back({b[1], b[2]});
        }
        
        // Sort events: first by x, then by height
        sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        
        multiset<int> heights;
        heights.insert(0); // ground level
        vector<vector<int>> result;
        int prevMax = 0;
        
        for (auto& e : events) {
            int x = e.first;
            int h = e.second;
            if (h < 0) {
                // start of building
                heights.insert(-h);
            } else {
                // end of building
                heights.erase(heights.find(h));
            }
            
            int currMax = *heights.rbegin();
            if (currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }
        
        return result;
    }
};
