class Solution {
public:
    int n, m;
    int total_walkable = 0;
    pair<int, int> start;
    pair<int, int> end;
    int ans = 0;
    
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};

    void solve(int i, int j, int cells_visited, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        // 1. Base Case: Check boundaries and obstacles first
        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == -1 || visited[i][j]) {
            return;
        }

        // 2. Base Case: Reached the destination
        if (i == end.first && j == end.second) {
            if (cells_visited == total_walkable) {
                ans += 1;
            }
            return;
        }

        // 3. Backtracking: Mark current cell as visited
        visited[i][j] = true;

        // 4. Explore all 4 neighbors
        for (int k = 0; k < 4; k++) {
            int new_r = i + r[k];
            int new_c = j + c[k];
            // Boundaries are safely checked at the start of the next recursive call
            solve(new_r, new_c, cells_visited + 1, grid, visited);
        }

        // 5. Backtracking: Unmark current cell
        visited[i][j] = false;
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

        // Total walkable cells includes start and end squares
        total_walkable = (n * m) - obstacles;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Start from step 1 because we are standing on the first walkable cell
        solve(start.first, start.second, 1, grid, visited);

        return ans;
    }
};
