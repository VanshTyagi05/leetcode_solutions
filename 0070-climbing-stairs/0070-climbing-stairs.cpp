class Solution {
public:
    int climb(int n,vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        int step1=climb(n-1,dp);
        int step2=climb(n-2,dp);
        return dp[n]=step1+step2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climb(n,dp);
    }
};