class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int>mp;
        int res = 0;
        int max_count = 0;
        int l = 0;

        for(int r = 0; r<s.length(); r++){
            mp[s[r]]++;
            max_count = max(max_count, mp[s[r]]);

            if(r-l+1 - max_count > k){
            mp[s[l]]--;
            l++;
            }
            res = max(res, r-l+1);
        }
        return res;

    }
};