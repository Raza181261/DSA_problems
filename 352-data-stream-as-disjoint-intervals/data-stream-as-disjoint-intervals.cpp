class SummaryRanges {
public:
    map<int, int> intervals;

    SummaryRanges() {}

    void addNum(int val) {
        int start = val, end = val;

        auto it = intervals.lower_bound(val);
        // Merge with next interval if adjacent
        if (it != intervals.end() && it->first == val + 1) {
            end = it->second;
            intervals.erase(it);
        }

        // Merge with previous interval if adjacent
        it = intervals.upper_bound(val);
        if (it != intervals.begin()) {
            auto prev = it; --prev;
            if (prev->second + 1 >= val) {
                start = prev->first;
                end = max(end, prev->second);
                intervals.erase(prev);
            }
        }

        intervals[start] = end;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &p : intervals)
            res.push_back({p.first, p.second});
        return res;
    }
};
