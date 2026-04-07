class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];

        int dx = x1 - x0;
        int dy = y1 - y0;

        for (int i = 2; i < coordinates.size(); i++) {
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];

            // Check if (y1 - y0) / (x1 - x0) == (yi - y0) / (xi - x0)
            // Using cross-multiplication: dy * (xi - x0) == (yi - y0) * dx
            if (dy * (xi - x0) != (yi - y0) * dx) {
                return false;
            }
        }
        return true;
    }
};
