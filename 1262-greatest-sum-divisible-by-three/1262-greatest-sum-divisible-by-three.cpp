class Solution {
public:
    int dp[40001][3];
    int helper(int idx,int rem,vector<int>&nums){
         if (idx == nums.size()) {
            return (rem == 0) ? 0 : -1e9; 
        }
        if(dp[idx][rem]!=-1)return dp[idx][rem];
        int skip=helper(idx+1,rem,nums);
        int new_rem=(nums[idx]+rem)%3;
        int include=nums[idx]+helper(idx+1,new_rem,nums);
        return dp[idx][rem]=max(include,skip);
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int result=helper(0,0,nums);
        if(result<0)return 0;

        return result;
    }
};