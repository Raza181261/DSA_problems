class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        for (int i = 3; i < n; i++) {
            // Case 1: current line crosses the line 3 steps ahead
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            
            // Case 2: current line meets the line 4 steps ahead
            if (i >= 4 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true;
            
            // Case 3: current line crosses the line 5 steps ahead
            if (i >= 5 && x[i-2] >= x[i-4] && x[i] + x[i-4] >= x[i-2] 
                && x[i-1] <= x[i-3] && x[i-1] + x[i-5] >= x[i-3]) return true;
        }
        return false;
    }
};
