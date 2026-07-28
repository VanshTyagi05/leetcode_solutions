class Solution {
public:
    int dp[305][305];

    int solve(int left, int right, vector<int>& nums) {

        // left aur right ke beech koi balloon nahi hai
        if (right - left == 1) {
            return 0;
        }

        // Already calculate ho chuka hai
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = 0;

        // k ko is range ka LAST burst balloon maan rahe hain
        for (int k = left + 1; k < right; k++) {

            int leftCoins = solve(left, k, nums);

            int rightCoins = solve(k, right, nums);

            // Jab k last burst hoga,
            // tab left aur right boundary uske neighbours honge
            int currentCoins = nums[left] * nums[k] * nums[right];

            ans = max(ans, leftCoins + currentCoins + rightCoins);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {

        // Boundary ke liye dono side 1 add karo
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));

        return solve(0, nums.size() - 1, nums);
    }
};
