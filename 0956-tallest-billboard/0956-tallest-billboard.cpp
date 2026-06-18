class Solution {
public:
   int n;
   int dp[21][10003];
   int solve(int i,int diff,vector<int>&rods){
    if(i>=n){
        if(diff==0)return 0;
        return INT_MIN;
    }
    if(dp[i][diff+5000]!=-1)return dp[i][diff+5000];
    int not_take=solve(i+1,diff,rods);
    int add_l1=rods[i]+solve(i+1,diff+rods[i],rods);
    int add_l2=rods[i]+solve(i+1,diff-rods[i],rods);

    return dp[i][diff+5000]= max({not_take,add_l1,add_l2});
   }
    int tallestBillboard(vector<int>& rods) {
       n=rods.size();
       memset(dp,-1,sizeof(dp)); 
       return solve(0,0,rods)/2;
    }
};