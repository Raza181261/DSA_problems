class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length() < k){
            int len = s.length();
            string ok = "";
            for(int i = 0; i<len; i++){
                char c = s[i];
                if(c == 'z'){
                    ok+='a';
                } else {
                    ok+=(char)(c+1);
                }
            }
            s+=ok;
        }
        return s[k-1];
    }
};