class Solution {
public:
    int N;
    int min_profit;
    int size;
    int result = 0;
    int M=1e9+7;
    // dp[idx][curr_members][curr_profit]
    int dp[102][102][102];
    int solve(int idx, vector<int>& group, vector<int>& profit, int members,
               int curr_profit) {

        if (idx >= size) {
            if (members <= N && curr_profit >= min_profit) {
                return 1;
            }
            return 0;
        }

        if(members>N){
            return 0; // jis path mai members ka count ek bar N se jyada hogya usme ab aage jane ki kya jrurt
        }

        if(dp[idx][members][curr_profit]!=-1){
           return dp[idx][members][curr_profit];
        }
        // take vala case dkeho
        int take=solve(idx + 1, group, profit, members + group[idx],
              min(curr_profit + profit[idx], min_profit));
        int not_take=solve(idx + 1, group, profit, members, curr_profit);

        return dp[idx][members][curr_profit]=(take+not_take)%M;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        N = n;
        size = profit.size();
        min_profit = minProfit;
        memset(dp,-1,sizeof(dp));
        return solve(0, group, profit, 0, 0);
        
    }
};