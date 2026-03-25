class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Fix: Suffix array size should match m
        vector<int> suffix_row(m);
        vector<int> prefix_row(m);

        // Row Prefix calculation
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += grid[i][j];
            prefix_row[i] = (i == 0) ? sum : sum + prefix_row[i - 1];
        }

        // 2. Fix: Start suffix from m-1 to avoid out-of-bounds (was i = m)
        for (int i = m - 1; i >= 0; i--) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += grid[i][j];
            suffix_row[i] = (i == m - 1) ? sum : sum + suffix_row[i + 1];
        }

        // Horizontal Cut Check
        for (int i = 0; i < m - 1; i++) {
            if (prefix_row[i] == suffix_row[i + 1])
                return true;
        }

        vector<int> suffix_col(n);
        vector<int> prefix_col(n);

        // Column Prefix calculation
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            prefix_col[j] = (j == 0) ? sum : sum + prefix_col[j - 1];
        }

        // Column Suffix calculation
        for (int j = n - 1; j >= 0; j--) {
            int sum = 0;
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            suffix_col[j] = (j == n - 1) ? sum : sum + suffix_col[j + 1];
        }

        // 3. Fix: Compare prefix of current vs suffix of NEXT (was
        // suffix_col[j])
        for (int j = 0; j < n - 1; j++) {
            if (prefix_col[j] == suffix_col[j + 1]) {
                return true;
            }
        }

        return false;
    }
};
