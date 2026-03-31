class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // Use cross multiplication: (y2-y1)*(x3-x2) != (y3-y2)*(x2-x1)
        int lhs = (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]);
        int rhs = (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]);

        return lhs != rhs;
    }
};