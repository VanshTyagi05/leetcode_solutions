class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1)
            return 0;

        // dp[i][j] will be true if substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Populate the palindrome DP table
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }

        // minCuts[i] stores the minimum cuts needed for substring s[0..i]
        vector<int> minCuts(n, 0);
        for (int i = 0; i < n; i++) {
            if (dp[0][i]) {
                minCuts[i] = 0; // No cuts needed if s[0..i] is a palindrome
            } else {
                int min_cut = i; // Maximum possible cuts
                for (int j = i; j > 0; j--) {
                    if (dp[j][i]) {
                        min_cut = min(min_cut, minCuts[j - 1] + 1);
                    }
                }
                minCuts[i] = min_cut;
            }
        }

        return minCuts[n - 1];
    }
};