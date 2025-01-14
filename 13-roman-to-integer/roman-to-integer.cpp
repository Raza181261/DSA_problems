class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_map;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;

        int total = 0;
        // int n = roman_map

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman_map[s[i]] < roman_map[s[i + 1]]) {
                total -= roman_map[s[i]];
            } else {
                total += roman_map[s[i]];
            }
        }
        total += roman_map[s[s.size() - 1]];

        return total;
    }
};