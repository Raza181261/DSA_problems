class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long upper = pow(10, n) - 1;
        long long lower = pow(10, n - 1);

        for (long long left = upper; left >= lower; --left) {
            string s = to_string(left);
            string rs = s;
            reverse(rs.begin(), rs.end());
            long long palin = stoll(s + rs); // create palindrome

            for (long long i = upper; i * i >= palin; --i) {
                if (palin % i == 0) {
                    return palin % 1337;
                }
            }
        }

        return 0;
    }
};
