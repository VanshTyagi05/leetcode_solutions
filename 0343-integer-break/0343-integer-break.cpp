class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        // Base case: for n=1, no break is possible that results in positive
        // integers, but we initialize dp[1] = 1 for the multiplication logic to
        // work.
        dp[1] = 1;

        // Build the table from 2 up to n
        for (int i = 2; i <= n; i++) {
            // Try every possible first cut 'j'
            for (int j = 1; j < i; j++) {
                /*
                   For each cut j, we have two options for the remaining part (i
                   - j):
                   1. (i - j): Don't break it further. Product = j * (i - j)
                   2. dp[i - j]: Use the best product from a previous
                   subproblem. Product = j * dp[i - j]
                */
                int currentMax = max(j * (i - j), j * dp[i - j]);

                // Update dp[i] with the maximum found among all possible cuts
                dp[i] = max(dp[i], currentMax);
            }
        }
        return dp[n];
    }
};