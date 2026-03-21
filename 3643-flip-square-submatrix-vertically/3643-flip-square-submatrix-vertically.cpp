class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int start=x;
        int end=x+k-1;
        while(start<end){
            // start aur end toh rows hai jinko swap krna hai
            for(int j=y;j<y+k;j++){
                swap(grid[start][j],grid[end][j]);
            }
            start++;
            end--;
        }
        return grid;
    }
};