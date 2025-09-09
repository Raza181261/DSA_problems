class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target, vector<int>& path,
               int start) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]); // take
            solve(candidates, target - candidates[i], path,i);        // not i+1 becaz we can reuse same element again
            path.pop_back(); // backTrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        solve(candidates, target, path, 0);
        return result;
    }
};