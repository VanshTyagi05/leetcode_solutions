class Solution {
public:
    int kadaneAlgo(vector<int>nums){
        int n=nums.size();
        if(n<2){
            return INT_MIN;
        }

        int current_max=nums[0]+nums[1];
        int global_max=current_max;
        for(int i=2;i<n;i++){
            current_max=max(current_max+nums[i],nums[i-1]+nums[i]);
            global_max=max(current_max,global_max);
        }

        return global_max;
    }
    int maxScore(vector<vector<int>>& grid) {
        // we must apply kadane algorithm for all rows and all columns
        int n=grid.size();
        int m=grid[0].size();
        // for startinng and ending row kadane algorithm cannot have 1 length
        // but for middle rows it can have single shared element
        
        // firtly apply for all rows
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
            ans=max(ans,kadaneAlgo(temp));
        }

        // now applying for all cloums
        for(int j=0;j<m;j++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                temp.push_back(grid[i][j]);
            }
            ans=max(ans,kadaneAlgo(temp));
        }

        // noe checking for singnle shared element 
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                ans=max(ans,grid[i][j]);
            }
        }

        return ans;
    }
};