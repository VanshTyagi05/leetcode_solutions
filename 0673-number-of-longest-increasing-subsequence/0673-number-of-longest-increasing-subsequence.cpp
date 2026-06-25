class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> cnt(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {

                    if (LIS[j] + 1 > LIS[i]) {
                        LIS[i] = 1 + LIS[j];
                        cnt[i] = cnt[j];
                    } else if (LIS[i] == LIS[j]+1) {
                        // same lenght ka ek aur LIS mila hai
                        cnt[i] += cnt[j];
                    }
                }
                maxLen = max(maxLen, LIS[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};