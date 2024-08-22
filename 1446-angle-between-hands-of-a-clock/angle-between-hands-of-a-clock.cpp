class Solution {
public:
    double angleClock(int hour, int minutes) {
        // positoin of hours
        float h = (hour % 12 + (float)minutes/60)*30;  //360/12=30 angle for each hour

        // position of minutes
        float m = minutes * 6;   // 360/60 angle for each minutes is 6

        float angle = abs(h-m);

        if(angle>180)
        angle = 360 - angle;

        return angle;
    }
};