class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        vector<int> curr = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            // if intervals overlap
            if (curr[1] >= intervals[i][0]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                // No overlap -> push current and switch
                result.push_back(curr);
                curr = intervals[i];
            }
            // Step 3: Push the last merged interval
        }
        result.push_back(curr);
        return result;
    }
};