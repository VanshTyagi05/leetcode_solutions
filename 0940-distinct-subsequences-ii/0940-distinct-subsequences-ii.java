import java.util.Arrays;

class Solution {
    private int MOD = 1_000_000_007;
    private int[] memo;
    private int[][] nextPos;

    public int distinctSubseqII(String s) {
        int n = s.length();
        memo = new int[n];
        Arrays.fill(memo, -1);

        // Precompute the next occurrence of each character to avoid duplicates
        nextPos = new int[n][26];
        int[] last = new int[26];
        Arrays.fill(last, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++) {
                nextPos[i][c] = last[c];
            }
            last[s.charAt(i) - 'a'] = i;
        }

        // Start the recursion from a virtual starting index
        long totalSubsequences = 0;
        for (int c = 0; c < 26; c++) {
            if (last[c] != -1) {
                totalSubsequences = (totalSubsequences + solve(last[c], s)) % MOD;
            }
        }

        return (int) totalSubsequences;
    }

    private int solve(int idx, String s) {
        // If already calculated, return the memoized result
        if (memo[idx] != -1) {
            return memo[idx];
        }

        // Base case: every single character choice forms 1 valid subsequence ("" + character)
        long ans = 1;

        // Try appending any of the 26 possible distinct characters next
        for (int c = 0; c < 26; c++) {
            int nextIdx = nextPos[idx][c];
            if (nextIdx != -1) {
                ans = (ans + solve(nextIdx, s)) % MOD;
            }
        }

        memo[idx] = (int) ans;
        return memo[idx];
    }
}
