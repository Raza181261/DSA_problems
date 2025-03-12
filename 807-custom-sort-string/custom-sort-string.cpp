class Solution {
public:
    string customSortString(string order, string s) {
       vector<int> index(26,-1);

       for(int i = 0; i<order.size(); i++){
        char ch = order[i];
        index[ch-'a'] = i;
       }
       
        auto myComparater = [index](char& ch1, char& ch2){
            if(index[ch1-'a']<index[ch2-'a']){
                return true;
            }
            return false;
        };
        
        sort(begin(s),end(s),myComparater);
        return s;
    }
};