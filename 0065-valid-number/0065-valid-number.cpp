class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                // Signs can only be at the start or immediately after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            } else if (c == 'e' || c == 'E') {
                // Must have seen a digit before 'e' and only one 'e' allowed
                if (seenE || !seenDigit)
                    return false;
                seenE = true;
                seenDigit = false; // Reset to ensure a digit follows 'e'
            } else if (c == '.') {
                // Only one dot allowed, and it must appear before 'e'
                if (seenDot || seenE)
                    return false;
                seenDot = true;
            } else {
                // Any other character is invalid
                return false;
            }
        }
        return seenDigit; // Must end having seen at least one digit
    }
};
