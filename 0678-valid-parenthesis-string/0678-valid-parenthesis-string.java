class Solution {
    public boolean checkValidString(String s) {
        int openCount = 0;
        int starCount = 0;

        // 1. Left-to-right pass: Check if there are enough '(' and '*' to balance ')'
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                openCount++;
            } else if (ch == '*') {
                starCount++;
            } else { // ch == ')'
                if (openCount > 0) {
                    openCount--;
                } else if (starCount > 0) {
                    starCount--;
                } else {
                    return false; // Excess ')' that cannot be balanced
                }
            }
        }

        // Reset counters for the reverse pass
        int closeCount = 0;
        starCount = 0;

        // 2. Right-to-left pass: Check if there are enough ')' and '*' to balance '('
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if (ch == ')') {
                closeCount++;
            } else if (ch == '*') {
                starCount++;
            } else { // ch == '('
                if (closeCount > 0) {
                    closeCount--;
                } else if (starCount > 0) {
                    starCount--;
                } else {
                    return false; // Excess '(' that cannot be balanced
                }
            }
        }

        return true;
    }
}
