class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){ // this is condition jab tk carry zero nhi hoo jta
            int carry = (a & b) << 1; // carry calculate
            a = a ^ b; // sum without using operator
            b = carry; // carry ko next iteration k liye pass kr doo
        }
        return a;
    }
};