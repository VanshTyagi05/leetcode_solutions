class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        // dp[i] stores the max non-overlapping palindromes in the prefix s[0...i-1]
        int[] dp = new int[n + 1];
        
        for (int i = 0; i < n; i++) {
            // By default, the score at i+1 inherits the score from i
            dp[i + 1] = Math.max(dp[i + 1], dp[i]);
            
            // 1. Expand around i as an ODD length palindrome center (e.g., "aba")
            expand(s, i, i, k, dp);
            
            // 2. Expand around i and i+1 as an EVEN length palindrome center (e.g., "abba")
            expand(s, i, i + 1, k, dp);
        }
        
        return dp[n];
    }
    
    private void expand(String s, int left, int right, int k, int[] dp) {
        int n = s.length();
        while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
            int len = right - left + 1;
            
            // If we found a valid palindrome of length >= k
            if (len >= k) {
                // Update the DP state at the end of this palindrome (right + 1)
                // It takes the value from before the palindrome started (dp[left]) + 1
                dp[right + 1] = Math.max(dp[right + 1], dp[left] + 1);
                
                // Greedy choice: Stop expanding further for this center.
                // A longer palindrome from the same center will only hurt future matches.
                break; 
            }
            left--;
            right++;
        }
    }
}
