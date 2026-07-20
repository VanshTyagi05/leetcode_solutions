class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }

        int size=temp.size();
        // now we have to rotate the temp by k
        k=k%size;
        rotate(temp.rbegin(), temp.rbegin() + k, temp.rend());

        for(int idx=0;idx<size;idx++){
            int i=idx/m;
            int j=idx%m;
            grid[i][j]=temp[idx];
        }

        return grid;
    }
};