class Solution {
public:
    int n;
    int memo[50001]; // Fix 2: Added memoization array

    int solve(int i, vector<int>& stones) {
        if (i >= n) return 0;
        if (memo[i] != -1e9) return memo[i]; // Return cached result

        int result = -1e9; // Fix 3: Initialize with very small value
        int current_take = 0;

        // Take 1
        current_take = stones[i];
        result = max(result, current_take - solve(i + 1, stones));

        // Take 2
        if (i + 1 < n) {
            current_take += stones[i + 1];
            result = max(result, current_take - solve(i + 2, stones));
        }

        // Take 3
        if (i + 2 < n) {
            current_take += stones[i + 2]; // Fix 1: Summing correctly now
            result = max(result, current_take - solve(i + 3, stones));
        }

        return memo[i] = result; // Store and return
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        // Initialize memo with a value that won't occur naturally
        fill(memo, memo + n + 1, -1e9); 
        
        int diff = solve(0, stoneValue);
        if (diff == 0) return "Tie";
        return (diff > 0) ? "Alice" : "Bob";
    }
};
