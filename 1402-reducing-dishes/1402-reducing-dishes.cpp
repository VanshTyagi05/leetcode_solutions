class Solution {
public:
   int n;
   int dp[501][502];
    int solve(int idx, int curr_time,vector<int>&satisfaction){
          if(idx>=n){
            return 0;
          }
          if(dp[idx][curr_time]!=-1)return dp[idx][curr_time];
          int not_take=0+solve(idx+1,curr_time,satisfaction);
          int take=satisfaction[idx]*curr_time+solve(idx+1,curr_time+1,satisfaction);
          

          return dp[idx][curr_time]=max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // largest satisfaction value agr peeche hogi toh humare time last mai jyada hoga na toh overall answer badh jaega
        memset(dp,-1,sizeof(dp));
        return solve(0,1,satisfaction);
    }
};