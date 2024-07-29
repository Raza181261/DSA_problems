class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int>result(n+m,0);

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
               int mul = (num1[i] - '0') * (num2[j] - '0');
               int sum = mul + result[i+j+1];
               result[i+j+1] = sum % 10;
               result[i + j] += sum / 10;
            }
        }
        string resultStr;
        for(int num: result){
            if(!(resultStr.empty() && num == 0)){
                resultStr.push_back(num + '0');
            }
        }
        return resultStr.empty() ? "0" : resultStr;
    }
};