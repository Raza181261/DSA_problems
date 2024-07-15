class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) {
            // If k is zero, return an array of zeros
            return result;
        }
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            if (k > 0) {
                // Sum the next k elements
                for (int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
            } else {
                // Sum the previous -k elements
                for (int j = 1; j <= -k; ++j) {
                    sum += code[(i - j + n) % n];
                }
            }
            result[i] = sum;
        }
        
        return result;
    }
};