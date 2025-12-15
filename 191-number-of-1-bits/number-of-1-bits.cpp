class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
       while(n){
        count += (n%2); //this gives reminder
        n /= 2; // this gives simple divide 
       }
        return count;
    }
};