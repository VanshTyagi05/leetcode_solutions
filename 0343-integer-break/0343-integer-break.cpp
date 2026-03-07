class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n]; // further we cnt break
        int res=0;
        for(int j=1;j<n;j++){
          int product=j*max(n-j,helper(n-j,dp));
          res=max(res,product);
        }
        return dp[n]=res;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};