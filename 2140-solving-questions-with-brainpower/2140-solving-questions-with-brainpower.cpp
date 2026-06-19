class Solution {
public:
   int n;
    long long solve(int i,vector<vector<int>>& questions,vector<long long>&dp){
        if(i>=n)return 0; // not possible to ear any point if reahced end
        if(dp[i]!=-1)return dp[i];
        long long take=questions[i][0]+solve(i+1+questions[i][1],questions,dp);
        long long not_take=0+solve(i+1,questions,dp);
        return dp[i]=max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
         n=questions.size();
        vector<long long>dp(n+1,-1);
        return solve(0,questions,dp);
    }
};