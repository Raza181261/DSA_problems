class Solution {
public:
    int hammingWeight(int n) {
        //Approach 1 :
        // just we use one preDefine funtion
        //return __buildin_popcount(n)

         //Approach 2 :  
        int count = 0;

       while( n > 0){
        n = (n & (n-1));
        count++;
       }
        return count;
    }
};