class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans = "";
        string start = strs[0], end= strs[strs.size()-1];
        for(int i = 0; i<start.size(); i++){
            if(start[i] != end[i]){
                return ans;
            }
            ans += start[i];
        }
        return ans;
    }
};