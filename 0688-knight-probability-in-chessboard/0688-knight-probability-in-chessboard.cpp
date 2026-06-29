class Solution {
public:
   int N;
   double dp[26][26][101];
   int r[8]={-2,-1,+1,+2,+2,+1,-1,-2};
   int c[8]={+1,+2,+2,+1,-1,-2,-2,-1};
   double solve(int i,int j,int k){
        if(i<0 || i>=N || j<0 || j>=N)return 0;
        if(k==0){
            return 1.0;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        double result=0;
        for(int p=0;p<8;p++){
           int new_r=i+r[p];
           int new_c=j+c[p];
           result+=(double)solve(new_r,new_c,k-1);
        }

        return dp[i][j][k]=(double)result/8.0;
   }
    double knightProbability(int n, int k, int row, int column) {
        N=n;
       for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int m = 0; m < 101; m++) {
                    dp[i][j][m] = -1.0;
                }
            }
        }
        return solve(row,column,k);
    }
};