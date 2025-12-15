class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
       while(n){
        n = (n & (n-1)); // unset the right most bit 1 convert to 0;
        count++;
       }
        return count;
    }
};