#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    // 3D array for memoization: dp[row][col][left_neutralizations]
    // Initialized with a sentinel value representing an uncalculated state.
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, vector<vector<int>>& coins, int left) {
        // 1. Base Case: Out of bounds
        if (i >= m || j >= n)
            return -1e9;

        // Check if this subproblem has already been solved
        if (dp[i][j][left] != -2e9) {
            return dp[i][j][left];
        }

        // 2. Base Case: Reached the bottom-right destination
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] >= 0) {
                return coins[i][j];
            } else {
                if (left > 0)
                    return 0; // Neutralize the negative coin
                else
                    return coins[i][j]; // Forced to take the negative coin
            }
        }

        int max_profit = -1e9;

        if (coins[i][j] >= 0) {
            // Definitely he will collect and go both ways i.e right or down
            int right = coins[i][j] + solve(i, j + 1, coins, left);
            int down = coins[i][j] + solve(i + 1, j, coins, left);
            max_profit = max(right, down);

        } else {
            // If coins[i][j] < 0
            if (left > 0) {
                // He has a choice:
                // Option A: Neutralize this cell (count it as 0) and use 1
                // charge
                int take_neutralize = 0 + max(solve(i + 1, j, coins, left - 1),
                                              solve(i, j + 1, coins, left - 1));

                // Option B: Do NOT neutralize it, take the penalty, and save
                // the charge
                int take_penalty =
                    coins[i][j] + max(solve(i + 1, j, coins, left),
                                      solve(i, j + 1, coins, left));

                max_profit = max(take_neutralize, take_penalty);
            } else {
                // No charges left. He MUST take the penalty.
                max_profit = coins[i][j] + max(solve(i + 1, j, coins, left),
                                               solve(i, j + 1, coins, left));
            }
        }

        // Save the calculated answer in the DP table before returning
        return dp[i][j][left] = max_profit;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        // Initialize DP table with -2e9 (acting as a "not visited" marker)
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, -2e9)));

        return solve(0, 0, coins, 2);
    }
};
