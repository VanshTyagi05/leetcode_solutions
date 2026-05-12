class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int left = 0, right = 0;
        for (char ch : moves) {
            if (ch == 'L')
                left++;
            if (ch == 'R')
                right++;
        }
        int ans = 0;
        if (left > right) {
            // hum '_' ko bhi left mangege
            for (char ch : moves) {
                if (ch == 'L' || ch == '_') {
                    ans -= 1;
                } else {
                    ans += 1;
                }
            }
        } else {

            // hum '_' ko bhi right mangege
            for (char ch : moves) {
                if (ch == 'R' || ch == '_') {
                    ans += 1;
                } else {
                    ans -= 1;
                }
            }
        }

        return abs(ans);
    }
};