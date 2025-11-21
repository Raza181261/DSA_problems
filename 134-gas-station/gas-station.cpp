class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_kamai = accumulate(begin(gas), end(gas), 0);
        int total_kharch = accumulate(begin(cost), end(cost), 0);

        if (total_kamai < total_kharch)
            return -1;

        int total = 0;
        int result_idx = 0;

        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                result_idx = i + 1;
                total = 0;
            }
        }

        return result_idx;
    }
};