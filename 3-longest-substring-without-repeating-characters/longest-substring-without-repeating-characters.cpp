class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>charIndex;
        int max_length = 0;
        int start = 0;

        for(int end = 0; end < s.size(); end++){
            char curr_char = s[end];
            if(charIndex.find(curr_char) != charIndex.end() && charIndex[curr_char] >= start){
                start = charIndex[curr_char] + 1;
            }
            charIndex[curr_char] = end;
            max_length = max(max_length, end-start+1);
        }
        return max_length;
    }
};