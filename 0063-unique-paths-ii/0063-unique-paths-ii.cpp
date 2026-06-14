class Solution {
public:
    int m, n;
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || i < 0 || j >= n || j < 0)
            return 0;
        if (grid[i][j] == 1) {
            // obstacle mil gya ab yha se aage nhi ja skte
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1; // 1 possible way mil gya hai
        }

        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(i + 1, j, grid) + solve(i, j + 1, grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, obstacleGrid);
    }
};