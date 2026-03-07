class Solution {
public:
    int dp[1001][1001];
    int helper(int idx, vector<vector<int>>& pairs, int prev_idx) {

        if (idx >= pairs.size()) {
            return 0; // ab kuch nhi add ho skta
        }
        if(dp[idx][prev_idx+1]!=-1){
            return dp[idx][prev_idx+1];
        }
        int not_take = helper(idx + 1, pairs, prev_idx);
        int take = 0;
        if (prev_idx == -1 || pairs[prev_idx][1] < pairs[idx][0]) {
            take = 1 + helper(idx + 1, pairs, idx);
        }
        return dp[idx][prev_idx+1]=max(take, not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        memset(dp,-1,sizeof(dp));
        if (n == 1)
            return 1;
        // sending -1  as previous index becausse it is not always considerablet o include the first element
        return helper(0, pairs, -1);
    }
};