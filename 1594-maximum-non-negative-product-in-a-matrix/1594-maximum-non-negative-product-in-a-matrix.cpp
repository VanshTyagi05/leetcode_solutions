class Solution {
public:
    int m, n;
    int M = 1e9 + 7;
    // We need two memo tables: one for the max product and one for the min product at (i, j)
    long long memo_max[16][16], memo_min[16][16];
    bool visited[16][16];

    // Returns a pair: {max_product, min_product} starting from (i, j) to the bottom-right
    pair<long long, long long> recur(int i, int j, vector<vector<int>>& grid) {
        // Base Case: Reached the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return {(long long)grid[i][j], (long long)grid[i][j]};
        }

        if (visited[i][j]) return {memo_max[i][j], memo_min[i][j]};

        long long cur_max = -2e18, cur_min = 2e18;

        // Try moving Right
        if (j + 1 < n) {
            auto res = recur(i, j + 1, grid);
            long long p1 = grid[i][j] * res.first;
            long long p2 = grid[i][j] * res.second;
            cur_max = max({cur_max, p1, p2});
            cur_min = min({cur_min, p1, p2});
        }

        // Try moving Down
        if (i + 1 < m) {
            auto res = recur(i + 1, j, grid);
            long long p1 = grid[i][j] * res.first;
            long long p2 = grid[i][j] * res.second;
            cur_max = max({cur_max, p1, p2});
            cur_min = min({cur_min, p1, p2});
        }

        visited[i][j] = true;
        memo_max[i][j] = cur_max;
        memo_min[i][j] = cur_min;
        return {cur_max, cur_min};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(visited, false, sizeof(visited));
        
        auto ans = recur(0, 0, grid);
        
        // Final check: if the max product is negative, return -1
        return ans.first < 0 ? -1 : ans.first % M;
    }
};
