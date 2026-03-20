class Solution {
public:
   vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    // Boundary fix: Only iterate where a full k*k window fits
    vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

    for (int i = 0; i <= m - k; i++) {
        for (int j = 0; j <= n - k; j++) {
           set<int>st;
            for (int l = i; l < i + k; l++) {
                for (int b = j; b < j + k; b++) {
                    st.insert(grid[l][b]);
                }
            }

            
            
            int min_diff = INT_MAX; // Initialize to a large value
            int first=*st.begin();
            st.erase(first);
            for(int a:st){
                min_diff=min(min_diff,a-first);
                st.erase(a);
                first=a;
            }
            ans[i][j] = min_diff==INT_MAX?0:min_diff;
        }
    }
    return ans;
}

};