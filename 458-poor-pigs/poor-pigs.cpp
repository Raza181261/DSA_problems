class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie + 1; // Number of states per pig
        int pigs = 0;
        while (pow(times, pigs) < buckets) pigs++;
        return pigs;
    }
};
