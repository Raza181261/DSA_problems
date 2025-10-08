class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            // first appear: add num to ones
            // second appear: move num from ones to twos
            // third appear: clear from both ones and twos
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones; // the single number remains in ones
    }
};
