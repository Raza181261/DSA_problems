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
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            solve(candidates, target - candidates[i], path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(begin(candidates),end(candidates));
        solve(candidates, target, path, 0);
        return result;
    }
};