class Solution {
public:
    int n;
    long long dp[100001][2];
    long long solve(int idx, vector<int>& nums, bool isEven) {

        if (idx >= n) {
            return 0;
        }
       if(dp[idx][isEven]!=-1)return dp[idx][isEven];
        long long take = 0;
        if (isEven) {
            take = nums[idx] + solve(idx + 1, nums, false);
        } else {
            take = -nums[idx] + solve(idx + 1, nums, true);
        }

        long long not_take = solve(idx + 1, nums, isEven);

        return dp[idx][isEven]= max(take, not_take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, nums, true);
    }
};