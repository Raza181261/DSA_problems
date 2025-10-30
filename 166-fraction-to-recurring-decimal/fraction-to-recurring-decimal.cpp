class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res;
        // handle negative numbers
        if ((numerator < 0) ^ (denominator < 0)) res += '-';
        
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        res += to_string(num / den);
        num %= den;
        if (num == 0) return res;
        
        res += '.';
        unordered_map<long long, int> mp;
        while (num != 0) {
            if (mp.count(num)) {
                res.insert(mp[num], 1, '(');
                res += ')';
                break;
            }
            mp[num] = res.size();
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        
        return res;
    }
};
