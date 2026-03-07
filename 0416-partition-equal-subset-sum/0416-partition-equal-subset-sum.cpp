class Solution {
public:
    // Using int to store 3 states: -1 (unvisited), 0 (false), 1 (true)
    int solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (idx >= nums.size() || target < 0) return 0;
        
        if (dp[idx][target] != -1) return dp[idx][target];

        int take = 0;
        // Only "take" if the number fits in the remaining target
        if (nums[idx] <= target) {
            take = solve(idx + 1, nums, target - nums[idx], dp);
        }
        
        if (take == 1) return dp[idx][target] = 1;

        int not_take = solve(idx + 1, nums, target, dp);
        
        return dp[idx][target] = (take || not_take);
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int x : arr) sum += x;

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        // CHANGED: Size is target + 1, and initialized with -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return solve(0, arr, target, dp) == 1;
    }
};
