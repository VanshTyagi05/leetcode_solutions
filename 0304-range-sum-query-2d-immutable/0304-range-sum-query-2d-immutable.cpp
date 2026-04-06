class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0 || matrix[0].size() == 0)
            return;
        int m = matrix[0].size();

        sum.resize(n, vector<int>(m));

        // 1. Pehla element set karo
        sum[0][0] = matrix[0][0];

        // 2. Pehli Row fill karo (Row-wise prefix sum)
        for (int j = 1; j < m; j++) {
            sum[0][j] = sum[0][j - 1] + matrix[0][j];
        }

        // 3. Pehla Column fill karo (Column-wise prefix sum)
        for (int i = 1; i < n; i++) {
            sum[i][0] = sum[i - 1][0] + matrix[i][0];
        }

        // 4. Baki bacha matrix fill karo (Inclusion-Exclusion)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // Formula: Current + Top + Left - Diagonal
                sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] -
                            sum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = sum[row2][col2];

        // 5. Boundary checks handle karo (Inclusion-Exclusion)
        int topRect = (row1 > 0) ? sum[row1 - 1][col2] : 0;
        int leftRect = (col1 > 0) ? sum[row2][col1 - 1] : 0;
        int diagonalPart = (row1 > 0 && col1 > 0) ? sum[row1 - 1][col1 - 1] : 0;

        // Formula: Total - Top - Left + Diagonal (Dono mein jo common tha)
        return total - topRect - leftRect + diagonalPart;
    }
};
