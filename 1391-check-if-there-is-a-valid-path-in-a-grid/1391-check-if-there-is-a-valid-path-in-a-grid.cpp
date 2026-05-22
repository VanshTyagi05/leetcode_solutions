class Solution {
public:
    int n, m;
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},  {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, {6, {{-1, 0}, {0, 1}}}};

    bool dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& visited) {
        if (i == n - 1 && j == m - 1)
            return true; // reached end successfully
        visited[i][j] = true;
        // exploring all other directions
        for (auto dir : directions[grid[i][j]]) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m ||
                visited[new_i][new_j] == 1) {
                continue;
            }
            // pehle ye bhi check kro kya vapas bhi ja skte ho
            for (auto backdir : directions[grid[new_i][new_j]]) {
                if (new_i + backdir[0] == i && new_j + backdir[1] == j) {
                    if(dfs(grid, new_i, new_j, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        return dfs(grid,0,0,visited);
    }
};