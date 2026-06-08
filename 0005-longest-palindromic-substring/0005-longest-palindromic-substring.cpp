class Solution {
public:
    string longestPalindrome(string s) {
        // code here
        int n = s.size();
        if (n == 0)
            return "";
        int startIndex = 0;
        int maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans = "";
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }

                if (dp[i][j] && L > maxLen) {
                    maxLen = L;
                    startIndex = i;
                }
            }
        }

        return s.substr(startIndex, maxLen);
    }
};