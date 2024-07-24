class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        string result ="";

        // iterarte left to right -> to eleminate extra close braket
        int open = 0;

        for(int i = 0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){
                result.push_back(s[i]);

            }else if(s[i] == '('){
                open++;
                result.push_back(s[i]);
            }else if(open>0){
                open--;
                result.push_back(s[i]);
            }
        }
       
        // iterarte right to left -> to eleminate extra open braket

        string final_result = "";
        int close= 0;

        for(int i = result.length()-1; i>=0; i--){
            if(result[i] >='a' == result[i] <='z'){
                final_result.push_back(result[i]);
            }else if(result[i] == ')'){
                close++;
                final_result.push_back(result[i]);
            }else if(close>0){
                close--;
                final_result.push_back(result[i]);
            }
        } 

        reverse(final_result.begin(), final_result.end());

        return final_result;

    }
};