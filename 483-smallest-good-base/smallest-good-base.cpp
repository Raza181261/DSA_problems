class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        
        for (int m = 63; m >= 2; --m) { // length of representation
            long long k = pow(num, 1.0/m);
            if (k <= 1) continue;
            
            long long sum = 1, curr = 1;
            for (int i = 1; i <= m; ++i) {
                curr *= k;
                sum += curr;
            }
            
            if (sum == num) return to_string(k);
        }
        
        return to_string(num - 1); // smallest base is n-1
    }
};
