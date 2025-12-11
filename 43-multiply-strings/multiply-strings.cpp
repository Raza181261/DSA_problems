class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        vector<int> result(m+n,0);

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0'); // convert string to integer
                int sum = mul + result[i+j+1];
                result[i+j+1] = sum % 10;
                result[i+j] += sum/10;
            }
        }

        string final_res;
        for(int num : result){
            if(!(final_res.empty() && num == 0)){
                final_res.push_back(num + '0'); // convert integer to string
            }
        }
        return final_res.empty() ? "0" : final_res;
    }
};