class Solution {
public:
    int n1, n2;
    int dp[501][501];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i >= n1 || j >= n2)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i < n1 && j < n2 && nums1[i] == nums2[j]) {
            return 1 + solve(i + 1, j + 1, nums1, nums2);
        }
        int case1 = solve(i + 1, j, nums1, nums2);
        int case2 = solve(i, j + 1, nums1, nums2);

        return dp[i][j] = max(case1, case2);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};