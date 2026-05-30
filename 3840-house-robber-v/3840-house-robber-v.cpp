class Solution {
public:
    // Sirf 2D DP table ki zaroorat hai: [index][prev_robbed]
    // Isse memory consumption 80GB se ghat kar sirf ~1.6MB ho jayegi!
    long long dp[100001][2];

    long long solve(int idx, int prev_robbed, vector<int>& nums, vector<int>& colors) {
        if (idx >= nums.size()) return 0;

        if (dp[idx][prev_robbed] != -1) return dp[idx][prev_robbed];

        long long take = 0;
        long long not_take = 0;

        // Ghar ko NA LOOTNA (Hamesha valid hai)
        // Agar is ghar ko chhod rahe hain, toh agla ghar bina kisi color restriction ke loot sakte hain (prev_robbed = 0)
        not_take = solve(idx + 1, 0, nums, colors);

        // Ghar ko LOOTNA
        // Case A: Ya toh pichla ghar nahi loota (prev_robbed == 0)
        // Case B: Ya pichla ghar loota tha, par uska color alag tha
        if (prev_robbed == 0 || colors[idx] != colors[idx - 1]) {
            take = nums[idx] + solve(idx + 1, 1, nums, colors);
        }

        return dp[idx][prev_robbed] = max(take, not_take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp, -1, sizeof(dp));
        // Shuruat mein koi pichla ghar nahi loota, isliye prev_robbed = 0
        return solve(0, 0, nums, colors);
    }
};
