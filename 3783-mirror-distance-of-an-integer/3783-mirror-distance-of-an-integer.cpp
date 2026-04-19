class Solution {
public:
    int reverseNum(int x) {
        long long y = 0; // Use long long to handle potential overflow
        while (x > 0) {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        return (int)y;
    }
    int mirrorDistance(int n) {
        return abs(n-reverseNum(n));
    }
};