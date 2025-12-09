class Solution {
public:

    int help(int n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum += digit*digit;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow  = help(slow);
            fast = help(help(fast));
        }while(slow != fast);
        return slow == 1;
    }
};