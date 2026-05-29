class Solution {
public:
    int N;

    int helper(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= N) {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];
        int take = nums[idx] + helper(idx + 2, nums,dp);
        int not_take = 0 + helper(idx + 1, nums,dp);
        return dp[idx] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        N = n - 1;
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            // including the fist one
            if (i != n - 1)
                temp1.push_back(nums[i]);
            if (i != 0)
                temp2.push_back(nums[i]);
        }
        vector<int> dp1(N, -1);
        vector<int> dp2(N, -1);
        return max(helper(0, temp1, dp1), helper(0, temp2, dp2));
    }
};