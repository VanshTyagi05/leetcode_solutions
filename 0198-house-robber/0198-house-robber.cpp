class Solution {
public:
    int helper(int idx,vector<int>& nums,vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        // take the money from current house and then go two index
        int take=nums[idx]+helper(idx+2,nums,dp);
        int nottake=0+helper(idx+1,nums,dp);
        return dp[idx]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(0,nums,dp);
    }
};