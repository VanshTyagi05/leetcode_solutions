class Solution {
public:
  int M,N;
  
    int count_ones(string str){
        int count=0;
        for(int i=0;i<str.size();i++){
          if(str[i]=='1'){
            count++;
          }
        }
        return count;
    }
   // sum1s sum0s will track of total ones and zeroes added in the current subset
    int dp[601][101][101];
    int solve(int idx,vector<string>& strs,int sum1s,int sum0s){
        if(idx>=strs.size())return 0;
        // not take
        if(dp[idx][sum1s][sum0s]!=-1)return dp[idx][sum1s][sum0s];
        int count1s=count_ones(strs[idx]);
        int count0s=strs[idx].size()-count1s;
        // not take ke liye koi chkkr ni
        int not_take=solve(idx+1,strs,sum1s,sum0s);
        //if taken
        int take=0;
        if(count1s+sum1s<=N && count0s+sum0s<=M){
         take=1+solve(idx+1,strs,sum1s+count1s,sum0s+count0s);
        }
        
        return dp[idx][sum1s][sum0s]=max(take,not_take);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        M=m;
        N=n;
        memset(dp,-1,sizeof(dp));
      return solve(0,strs,0,0);
    }
};