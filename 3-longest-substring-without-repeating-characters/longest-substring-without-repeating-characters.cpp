class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charIndex;
        int maxLength = 0;
        int start = 0;

        for(int end = 0; end<s.size(); end++){
            char currChar = s[end];
            if(charIndex.find(currChar) != charIndex.end() && charIndex[currChar] >= start){
                start = charIndex[currChar]+1;
            }
            charIndex[currChar] = end;
            maxLength = max(maxLength,end-start+1);
        }
        return maxLength;
    }
};