class Solution {
public:
    int r[4] = {-1, 0, +1, 0};
    int c[4] = {0, +1, 0, -1};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < sources.size(); i++) {
            int ri = sources[i][0];
            int ci = sources[i][1];
            int color = sources[i][2];
            grid[ri][ci]=color;
            time[ri][ci]=0;
            q.push({{ri, ci}, 0});
            //{{row,col},time} // 
        }
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int color=grid[row][col];
            int currT = it.second;
            for (int i = 0; i < 4; i++) {
                int newr = row + r[i];
                int newc = col + c[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {

                    // if the time is different 
                   if(time[newr][newc]>currT+1){
                     time[newr][newc] = currT + 1;
                        grid[newr][newc] = color;
                        q.push({{newr, newc}, currT + 1});
                   }
                   else if(time[newr][newc]==currT+1){
                    grid[newr][newc]=max(grid[newr][newc],color);
                   }
                }
            }
        }
        return grid;
    }
};