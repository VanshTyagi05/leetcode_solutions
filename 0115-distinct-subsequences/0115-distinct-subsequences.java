class Solution {
    public int recur(int i, int j, String s, String t, int[][] memo) {
        if (j == 0)
            return 1; // If t is empty, there's one subsequence (no characters)
        if (i == 0)
            return 0; // If s is empty and t is not, there's no matching subsequence
        if (memo[i][j] != -1)
            return memo[i][j];
        // both charcters matched then either take it or not take it
        if (s.charAt(i-1) == t.charAt(j-1)) {
            memo[i][j] = recur(i - 1, j - 1, s, t, memo) + recur(i - 1, j, s, t, memo);
        } else {
            memo[i][j] = recur(i - 1, j, s, t, memo);
        }

        return memo[i][j];
    }

    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] memo = new int[m + 1][n + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return recur(m,n, s, t, memo);
    }
}