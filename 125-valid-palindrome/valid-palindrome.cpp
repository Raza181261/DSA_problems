class Solution {
public:
    bool isPalindrome(string s) {

        if(s.size()<=1) return true; // to check if string is null or having 1 character
        
        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end]))
              return false;
            else{
            start++;
            end--;
            }
        }
        return true;
        
    }
};