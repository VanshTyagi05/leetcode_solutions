class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle=((hour%12)*30)+((minutes/60.0)*30);
        double minutesangle=minutes*6.0; // ye toh simple hai
        double diff=abs(hourangle-minutesangle);

        return min(diff,360-diff);
        
    }
};