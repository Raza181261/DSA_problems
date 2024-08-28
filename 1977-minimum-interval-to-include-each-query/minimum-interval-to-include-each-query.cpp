class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         sort(intervals.begin(), intervals.end());

        // Pair of query value and its index in the original array
        vector<pair<int, int>> queryIndex;
        for (int i = 0; i < queries.size(); ++i) {
            queryIndex.push_back({queries[i], i});
        }
        
        // Sort queries by their value
        sort(queryIndex.begin(), queryIndex.end());

        // Min-heap to store intervals based on their length
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<int> result(queries.size(), -1);
        int i = 0;
        for (auto& [query, idx] : queryIndex) {
            // Add all intervals that start before or at the query value
            while (i < intervals.size() && intervals[i][0] <= query) {
                int length = intervals[i][1] - intervals[i][0] + 1;
                // Push {length, end} into the min-heap
                minHeap.push({length, intervals[i][1]});
                ++i;
            }

            // Remove intervals from the heap that don't include the current query
            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            // If the heap is not empty, the top of the heap is the minimum interval that includes the query
            if (!minHeap.empty()) {
                result[idx] = minHeap.top().first;
            }
        }

        return result;
    }
};
