class Solution {
public:
    int n, m;
    int total_walkable;
    pair<int, int> start;
    pair<int, int> end;
    int ans = 0;
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    void solve(int i, int j, int curr_steps, vector<vector<int>>& grid,
               vector<vector<bool>>& visited) {
        // if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == -1 ||
        //     visited[i][j]) {
        //     // invalid state hai
        //     // a gr already visited hai toh bhi vapas ho jao
        //     return;
        // }
        if (i == end.first && j == end.second) {
            // bhaii end mai phocuh gye hai
            if (curr_steps == total_walkable) {
                ans += 1;
            }
            return;
        }
        visited[i][j] = 1; // mark as viisted
        for (int k = 0; k < 4; k++) {
            int new_r = i + r[k];
            int new_c = j + c[k];
            // FIX 1: Safely check boundaries before accessing arrays
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {
                if (!visited[new_r][new_c] && grid[new_r][new_c] != -1) {
                    solve(new_r, new_c, curr_steps + 1, grid, visited);
                }
            }
            // mark as unviisted
        }
        visited[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int obstacles = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                } else if (grid[i][j] == 2) {
                    end = {i, j};
                } else if (grid[i][j] == -1) {
                    obstacles++;
                }
            }
        }

        int total = n * m;
        total_walkable = total - obstacles;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[start.first][start.second] = 1; // strting cell is viisted
        solve(start.first, start.second, 1, grid, visited);

        return ans;
    }
};