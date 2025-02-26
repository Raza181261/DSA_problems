class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>freq;

        for(char m: magazine){
            freq[m]++;
        }

        for(char r: ransomNote){
            if(freq[r]>0){
                freq[r]--;
            }else{
                return false;
            }
        }
        return true;
    }
};