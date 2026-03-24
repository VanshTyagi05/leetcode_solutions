class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long product = 1;
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = product; // before i, j  store the entire product
                                   // intoo p[i][j]
                product = (product * grid[i][j]) % 12345;
            }
        }
        product = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * product) % 12345;
                product = (product * grid[i][j]) % 12345;
            }
        }
        return p;
    }
};