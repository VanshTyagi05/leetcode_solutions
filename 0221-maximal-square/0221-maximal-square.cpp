class Solution {
public:
   int m,n;
    int dp[301][301];
    int solve(int i,int j,vector<vector<char>>& matrix){
         if(i>=m || j>=n || matrix[i][j]=='0'){
            return 0; // i.e out of bound case
         }
         
        if(dp[i][j]!=-1)return dp[i][j];
         int right=solve(i,j+1,matrix);
         int down=solve(i+1,j,matrix);
         int diag=solve(i+1,j+1,matrix);

       
         return dp[i][j]= 1+min({right, down, diag});

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                 ans=max(ans,solve(i,j,matrix));
                }
            }
        }
        return ans*ans;
    }
};