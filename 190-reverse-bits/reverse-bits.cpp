class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i = 0; i<32; i++){
            int bit = n & 1;  // take last bit of n
            result <<= 1;  // shift result left
            result |= bit;  // add the bit
            n >>= 1;    // shift n right
        }
        return result;
    }
};