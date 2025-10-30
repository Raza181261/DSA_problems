class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--; // since we start from 1

        while (k > 0) {
            long long steps = calcSteps(n, curr, curr + 1);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }

private:
    long long calcSteps(int n, long long n1, long long n2) {
        long long steps = 0;
        while (n1 <= n) {
            steps += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};
