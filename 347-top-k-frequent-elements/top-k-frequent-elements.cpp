class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 1. make a map
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // 2. create a heap
        priority_queue<P, vector<P>, greater<P>> pq;

        // 3.
        for (auto& it : mp) {
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};