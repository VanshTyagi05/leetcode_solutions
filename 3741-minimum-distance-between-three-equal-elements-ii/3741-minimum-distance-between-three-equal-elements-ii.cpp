class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto const& [key, val_vec] : mp) {
            if (val_vec.size() < 3)
                continue;
            // Slide a window of size 3 across the indices
            for (int i = 0; i <= (int)val_vec.size() - 3; i++) {
                int idx1 = val_vec[i];
                int idx3 = val_vec[i + 2];

                // Simplified formula: 2 * (largest_idx - smallest_idx)
                int current_dist = 2 * (idx3 - idx1);
                ans = min(ans, current_dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};