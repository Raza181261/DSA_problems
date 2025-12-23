class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while(x != 0){
            int digit = x % 10; // for calculate last digit in x
            x = x / 10; // Original number chhota karna

            if(rev > INT_MAX/10 || rev < INT_MIN/10){ // check overflow case
                return 0;
            }

            rev = rev * 10 + digit; // for converting reverse number
        }
        return rev;
    }
};