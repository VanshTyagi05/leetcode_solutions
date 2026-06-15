class Solution {
public:
    int n;
    int M = 1e9 + 7;
    int dp[100001];
    int solve(int start, string& s, int& k) {
        if (start >= n) {
            return 1;
        }
        if(dp[start]!=-1)return dp[start];
        if (s[start] == '0')
            return 0;
        long long num = 0;
        int ans = 0;
        for (int end = start; end < n; end++) {
            num = (num * 10) + (s[end] - '0');
            if (num > k)
                break;
            ans = (ans + solve(end + 1, s, k)) % M;
        }

        return dp[start]=ans;
    }
    int numberOfArrays(string s, int k) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, s, k);
    }
};