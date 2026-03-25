class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;

        // Calculate total sum of the grid
        for (const auto& row : grid)
            for (int val : row) totalSum += val;

        // Total sum must be even to split into two equal integers
        if (totalSum % 2 != 0) return false;
        long long target = totalSum / 2;

        // Check horizontal cuts
        long long currentPrefixSum = 0;
        for (int i = 0; i < m - 1; i++) { // m-1 because we need two parts
            for (int j = 0; j < n; j++) {
                currentPrefixSum += grid[i][j];
            }
            if (currentPrefixSum == target) return true;
        }

        // Check vertical cuts
        currentPrefixSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                currentPrefixSum += grid[i][j];
            }
            if (currentPrefixSum == target) return true;
        }

        return false;
    }
};
