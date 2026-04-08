class Solution {
public:
    int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (int i = 0; i < queries.size(); i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];
            int idx = li;
            while (idx <= ri) {
            
                nums[idx] = (1LL*nums[idx] * vi) % mod;
                idx += ki;
            }
        }
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};