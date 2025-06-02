class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n>m){
            return false; 
        }

        sort(begin(s1),end(s1));

        for(int i = 0; i<=m-n; i++){
            string subString = s2.substr(i,n);
            sort(begin(subString),end(subString));
            if(s1 == subString){
                return true;
            }
        }
        return false;
    }
};