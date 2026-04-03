class Solution {
public:
    int m, n;
    int dp[301][301];
    int solve(vector<vector<char>>& matrix) {
        memset(dp, 0, sizeof(dp));
        int maxSide=0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // IMPORTANT: Only calculate if the current cell is '1'
                if (matrix[i][j] == '1') {
                    int right = (j + 1 < n) ? dp[i][j + 1] : 0;
                    int down = (i + 1 < m) ? dp[i + 1][j] : 0;
                    int diag = (i + 1 < m && j + 1 < n) ? dp[i + 1][j + 1] : 0;

                    dp[i][j] = 1 + min({right, down, diag});

                    // Track the largest side found so far
                    maxSide = max(maxSide, dp[i][j]);
                } else {
                    dp[i][j] = 0; // Explicitly set to 0 if matrix cell is '0'
                }
            }
        }

        return maxSide*maxSide;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        return solve(matrix);
        
    }
};