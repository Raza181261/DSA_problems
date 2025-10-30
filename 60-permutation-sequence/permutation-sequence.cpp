class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        
        // calculate (n-1)! and store numbers 1 to n
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        string ans = "";
        k = k - 1; // convert to 0-based index
        
        while (!numbers.empty()) {
            int index = k / fact;
            ans += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) break;
            
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    }
};
