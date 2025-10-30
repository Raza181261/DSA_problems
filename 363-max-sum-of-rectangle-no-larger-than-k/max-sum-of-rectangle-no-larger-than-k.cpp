class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;

        for (int left = 0; left < n; ++left) {
            vector<int> rowSum(m, 0);
            for (int right = left; right < n; ++right) {
                for (int i = 0; i < m; ++i) rowSum[i] += matrix[i][right];

                // Find max subarray sum <= k
                set<int> cumSet;
                cumSet.insert(0);
                int cumSum = 0;
                for (int sum : rowSum) {
                    cumSum += sum;
                    auto it = cumSet.lower_bound(cumSum - k);
                    if (it != cumSet.end()) res = max(res, cumSum - *it);
                    cumSet.insert(cumSum);
                }
            }
        }
        return res;
    }
};
