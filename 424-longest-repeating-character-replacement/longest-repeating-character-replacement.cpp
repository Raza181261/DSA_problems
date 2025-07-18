class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        int left = 0, maxCount = 0, result = 0;
        vector<int> count(26,0);

        for(int right = 0; right < s.size(); right++){
           count[s[right] - 'A']++;
           maxCount = max(maxCount,count[s[right]-'A']);

           while((right-left+1) - maxCount > k ){
              count[s[left] - 'A']--;
              left++;
           }
           result = max(result,right-left+1);
        }
        return result;
    }
};