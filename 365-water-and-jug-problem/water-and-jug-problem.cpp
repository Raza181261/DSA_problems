class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // If target is greater than sum of both jugs, impossible
        if (targetCapacity > jug1Capacity + jug2Capacity) return false;
        
        // If target is 0, it's always possible
        if (targetCapacity == 0) return true;
        
        // Use GCD approach
        int gcdVal = gcd(jug1Capacity, jug2Capacity);
        return targetCapacity % gcdVal == 0;
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
