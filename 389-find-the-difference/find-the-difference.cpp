class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char,int>mp;
        for(char ch1:s){
            mp[ch1]++;
        }
        for(char ch2:t){
            if(mp[ch2]>0){
                mp[ch2]--;
            }else{
            return ch2;
            }
        }
        return 0;
    }
};