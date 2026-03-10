class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int max_len=0;
        for(int x:arr){
            dp[x]=dp[x-difference]+1;
            max_len=max(max_len,dp[x]);
        }
        return max_len;
    }
};