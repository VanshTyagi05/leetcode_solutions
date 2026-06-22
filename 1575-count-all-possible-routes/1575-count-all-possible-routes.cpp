class Solution {
public:
    int n;
    int dp[101][201];
    int mod=1e9+7;
    int solve(vector<int>& locations, int i, int finish, int fuel) {
        if (fuel < 0)
            return 0;
        int ans = 0;
        if(dp[i][fuel]!=-1)return dp[i][fuel];
        if (i == finish) {
            ans += 1;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                int remain_fuel = fuel - abs(locations[i] - locations[j]);
                ans = (ans + solve(locations, j, finish, remain_fuel))%mod;
            }
        }
        return dp[i][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(locations, start, finish, fuel);
    }
};