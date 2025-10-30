class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n != 0) return -1; // impossible
        
        int target = total / n;
        int res = 0, cum = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = machines[i] - target;
            cum += diff;
            res = max(res, max(abs(cum), diff));
        }
        
        return res;
    }
};
