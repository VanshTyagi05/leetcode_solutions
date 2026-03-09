class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;

        // 1. Find the maximum value to define our range
        int max_val = 0;
        for (int num : nums)
            max_val = max(max_val, num);

        // 2. Precompute total points for each unique value
        // sums[i] = frequency of i * value i
        vector<int> sums(max_val + 1, 0);
        for (int num : nums) {
            sums[num] += num;
        }

        // 3. Initialize memoization table with -1 (meaning uncomputed)
        vector<int> memo(max_val + 1, -1);

        return solve(0, max_val, sums, memo);
    }

private:
    int solve(int i, int max_val, const vector<int>& sums, vector<int>& memo) {
        // Base case: if we go beyond the possible values
        if (i > max_val) {
            return 0;
        }

        // Return the cached result if we've solved this subproblem already
        if (memo[i] != -1) {
            return memo[i];
        }

        // Option 1: Skip current value 'i', move to 'i + 1'
        int skip = solve(i + 1, max_val, sums, memo);

        // Option 2: Take all instances of 'i', must skip 'i + 1' (move to 'i +
        // 2')
        int take = sums[i] + solve(i + 2, max_val, sums, memo);

        // Store and return the best choice
        return memo[i] = max(skip, take);
    }
};