class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int high = s.size();
        vector<int>result;

        for(char c : s){
            if(c == 'I'){
                result.push_back(low++);
            }else{
                result.push_back(high--);
            }

        }
        result.push_back(low);
        return result;
    }
};