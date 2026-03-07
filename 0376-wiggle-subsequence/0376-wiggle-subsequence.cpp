class Solution {
public:
    // memo[idx][isUp]
    int dp[1001][2];

    int recur(int idx, bool isUp, vector<int>& nums) {
        if (idx == nums.size()) return 0;
        if (dp[idx][isUp] != -1) return dp[idx][isUp];

        // Option 1: Skip current element
        int res = recur(idx + 1, isUp, nums);

        // Option 2: Take current element (if it satisfies the wiggle)
        // isUp == 1 means we are looking for a number GREATER than nums[idx-1]
        // isUp == 0 means we are looking for a number SMALLER than nums[idx-1]
        if (isUp && nums[idx] > nums[idx - 1]) {
            res = max(res, 1 + recur(idx + 1, false, nums));
        } else if (!isUp && nums[idx] < nums[idx - 1]) {
            res = max(res, 1 + recur(idx + 1, true, nums));
        }

        return dp[idx][isUp] = res;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        // Initialize memo
        for(int i = 0; i < n; i++) {
            dp[i][0] = dp[i][1] = -1;
        }

        // We always take the first element (count starts at 1).
        // From index 1, we try two paths: 
        // 1. Next move must be UP
        // 2. Next move must be DOWN
        return 1 + max(recur(1, true, nums), recur(1, false, nums));
    }
};
