class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        vector<int> ans;
        set<int> s(nums.begin(), nums.end());
        for (int i = mini; i <= maxi; i++) {
            if (s.contains(i) == false) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};