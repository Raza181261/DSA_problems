class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        
        // Map word to its index
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            reverse(w.begin(), w.end());
            mp[w] = i;
        }
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int n = word.size();
            
            for (int j = 0; j <= n; j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                // If left is palindrome, check reversed right in map
                if (isPalindrome(left) && mp.count(right) && mp[right] != i) {
                    res.push_back({mp[right], i});
                }
                
                // If right is palindrome, check reversed left in map
                // j != n to avoid duplicates
                if (j != n && isPalindrome(right) && mp.count(left) && mp[left] != i) {
                    res.push_back({i, mp[left]});
                }
            }
        }
        
        return res;
    }
    
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
