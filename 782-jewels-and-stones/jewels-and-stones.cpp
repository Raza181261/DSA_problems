class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp1;
        int count = 0;

        for(char ch: jewels){
            mp1[ch]++;
        }
       for(char st: stones){
        if(mp1.find(st) != mp1.end()){
            count += mp1[st];
        }
       }
       return count;
    }
};