class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Case 1: Distance from the first house (index 0) to the furthest different color
        for (int i = n - 1; i > 0; i--) {
            if (colors[i] != colors[0]) {
                maxDist = max(maxDist, i);
                break;
            }
        }

        // Case 2: Distance from the last house (index n-1) to the furthest different color
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, (n - 1) - i);
                break;
            }
        }

        return maxDist;
    }
};
