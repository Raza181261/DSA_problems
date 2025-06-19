class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n < m) {
            return "";
        }
        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }

        int requiredCount = m;
        int windowSize = INT_MAX;
        int start_i = 0;

        int i = 0;
        int j = 0;

        while (j < n) {
            char ch = s[j];
            if (mp[ch] > 0)
                requiredCount--;
            mp[ch]--;

            while (requiredCount == 0) {
                int currWindowSize = j - i + 1;

                if (windowSize > currWindowSize) {
                    windowSize = currWindowSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    requiredCount++;
                }
                i++;
            }

            j++;
        }
        return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
    }
};