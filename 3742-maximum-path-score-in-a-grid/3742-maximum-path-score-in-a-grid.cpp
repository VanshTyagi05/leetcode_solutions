class Solution {
public:
    int n, m;
    // Use a 3D vector to safely allocate memory on the heap instead of the stack
    vector<vector<vector<int>>> dp; 

    int recur(int i, int j, vector<vector<int>>& grid, int rem_k) {
        // 1. Out-of-bounds check
        if (i >= n || j >= m || rem_k < 0) {
            return -1e9;
        }

        // 2. Base Case: Reached Destination
        if (i == n - 1 && j == m - 1) {
            int final_cell_cost = (grid[i][j] > 0) ? 1 : 0;
            if (final_cell_cost <= rem_k) {
                return grid[i][j];
            }
            return -1e9;
        }

        // 3. Return memoized result if already calculated
        if (dp[i][j][rem_k] != -1) {
            return dp[i][j][rem_k];
        }

        // 4. Calculate cost to step on this current cell
        int current_cost = (grid[i][j] > 0) ? 1 : 0;

        // 5. Explore paths ahead safely
        int right = -1e9;
        int down = -1e9;

        if (rem_k - current_cost >= 0) {
            right = recur(i, j + 1, grid, rem_k - current_cost);
            down = recur(i + 1, j, grid, rem_k - current_cost);
        }

        int maxforward = max(right, down);
        
        // If no future path is valid, save state as invalid
        if (maxforward < 0) {
            return dp[i][j][rem_k] = -1e9;
        }

        return dp[i][j][rem_k] = grid[i][j] + maxforward;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        
        // Safely resize the heap-allocated DP table to perfectly match constraints
        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        int ans = recur(0, 0, grid, k);
        return (ans < 0) ? -1 : ans;
    }
};
