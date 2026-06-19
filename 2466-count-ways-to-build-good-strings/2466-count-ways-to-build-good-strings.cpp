class Solution {
public:
    int L, H, Z, O;
    int M = 1e9 + 7;
    int solve(int len, vector<int>& dp) {

        // Base Case
        if (len > H)
            return 0;

        if (dp[len] != -1)
            return dp[len];
        int ans = 0;

        // Agar current length valid hai to count karo
        if (len >= L)
            ans++;

        // Aage aur strings banao
        ans = (ans + solve(len + Z, dp)) % M;
        ans = (ans + solve(len + O, dp)) % M;

        return dp[len] = ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        L = low;
        H = high;
        Z = zero;
        O = one;
        vector<int> dp(H + 1, -1);
        return solve(0, dp);
    }
};