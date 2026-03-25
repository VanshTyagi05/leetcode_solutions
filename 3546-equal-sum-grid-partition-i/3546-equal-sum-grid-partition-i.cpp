class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return false;
        int n = grid[0].size();

        // Keep input as int, but use long long for storage and sums
        vector<long long> prefix_row(m);
        vector<long long> suffix_row(m);

        // Row calculations
        for (int i = 0; i < m; i++) {
            long long row_sum = 0;
            for (int j = 0; j < n; j++)
                row_sum += grid[i][j]; // Accumulate in long long
            prefix_row[i] = (i == 0) ? row_sum : row_sum + prefix_row[i - 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            long long row_sum = 0;
            for (int j = 0; j < n; j++)
                row_sum += grid[i][j];
            suffix_row[i] =
                (i == m - 1) ? row_sum : row_sum + suffix_row[i + 1];
        }

        for (int i = 0; i < m - 1; i++) {
            if (prefix_row[i] == suffix_row[i + 1])
                return true;
        }

        // Column calculations
        vector<long long> prefix_col(n);
        vector<long long> suffix_col(n);

        for (int j = 0; j < n; j++) {
            long long col_sum = 0;
            for (int i = 0; i < m; i++)
                col_sum += grid[i][j];
            prefix_col[j] = (j == 0) ? col_sum : col_sum + prefix_col[j - 1];
        }

        for (int j = n - 1; j >= 0; j--) {
            long long col_sum = 0;
            for (int i = 0; i < m; i++)
                col_sum += grid[i][j];
            suffix_col[j] =
                (j == n - 1) ? col_sum : col_sum + suffix_col[j + 1];
        }

        for (int j = 0; j < n - 1; j++) {
            if (prefix_col[j] == suffix_col[j + 1])
                return true;
        }

        return false;
    }
};
