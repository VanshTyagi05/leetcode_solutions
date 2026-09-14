class Solution {
    public boolean isRectangleOverlap(int[] rect1, int[] rect2) {
        // Check if either rectangle is actually a line (has 0 area)
        if (rect1[0] == rect1[2] || rect1[1] == rect1[3] ||
                rect2[0] == rect2[2] || rect2[1] == rect2[3]) {
            return false;
        }

        // Check if rect1 is completely to the left, right, above, or below rect2
        return !(rect1[2] <= rect2[0] || // rect1 is completely left of rect2
                rect1[0] >= rect2[2] || // rect1 is completely right of rect2
                rect1[3] <= rect2[1] || // rect1 is completely below rect2
                rect1[1] >= rect2[3]); // rect1 is completely above rect2
    }
}
