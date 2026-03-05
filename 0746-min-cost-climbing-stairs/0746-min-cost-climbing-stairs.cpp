class Solution {
public:
    int fun(int idx,vector<int>&cost,vector<int>&dp){
        if(idx>=cost.size()){
            return 0; // we have reached the top
        }
        if(dp[idx]!=-1)return dp[idx];
        //first cvhoice climb only ne step
        int onestep=cost[idx]+fun(idx+1,cost,dp);
        int twostep=cost[idx]+fun(idx+2,cost,dp);
        return dp[idx]=min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int strting0=fun(0,cost,dp);
        int strting1=fun(1,cost,dp);
        return min(strting0,strting1);
    }
};