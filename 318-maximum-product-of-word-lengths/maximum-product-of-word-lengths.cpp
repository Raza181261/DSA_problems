class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);

        // Compute bitmask for each word
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
        }

        int maxProd = 0;
        // Compare all pairs
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) { // No common letters
                    maxProd = max(maxProd, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return maxProd;
    }
};
