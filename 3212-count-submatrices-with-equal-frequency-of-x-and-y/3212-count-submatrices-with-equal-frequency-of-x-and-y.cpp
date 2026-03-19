class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> countX(n, vector<int>(m, 0));
        vector<vector<int>> countY(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                countX[i][j] = (grid[i][j] == 'X');
                countY[i][j] = (grid[i][j] == 'Y');
                if (i - 1 >= 0 ) {
                    countX[i][j] += countX[i - 1][j];
                    countY[i][j]+=countY[i-1][j];
                }
                 if (j - 1 >= 0 ) {
                    countX[i][j] += countX[i][j-1];
                    countY[i][j]+=countY[i][j-1];
                }
                 if (i - 1 >= 0 && j-1>=0) {
                    countX[i][j] -= countX[i - 1][j-1];
                    countY[i][j]-=countY[i-1][j-1];
                }

                if ((countX[i][j] == countY[i][j]) && countX[i][j] >= 1)
                    ans++;
            }
        }
        return ans;
    }
};