class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3) return 0;
        int count = 0 ;

        for(int i = 0; i<=s.length()-3; i++){
            string subString = s.substr(i, 3);
            if(isUnique(subString)){
                count++;
            }
        }
        return count;
    }
    private:
    bool isUnique(const string& s){
        unordered_set <char> charSet;
        for(char c : s){
            if(charSet.find(c) != charSet.end()){
                return false;
            }
            charSet.insert(c);
        }
        return true;
};


 };