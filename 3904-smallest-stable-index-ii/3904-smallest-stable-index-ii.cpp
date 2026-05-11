class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n, INT_MIN);
        vector<int> mini(n, INT_MAX);
        int maxnum = nums[0];
        int minnum = nums[n - 1];
        for (int i = 0; i < n; i++) {
            maxnum = max(maxnum, nums[i]);
            maxi[i] = maxnum;
        }
        for (int i = n - 1; i >= 0; i--) {
            minnum = min(minnum, nums[i]);
            mini[i] = minnum;
        }
        for (int i = 0; i < n; i++) {
            if ((maxi[i] - mini[i]) <= k) {
                return i;
            }
        }

        return -1;
    }
};