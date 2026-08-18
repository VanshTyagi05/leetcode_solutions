class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>
            mp; // har ek element ki frequency ko k size subarray mai hai
                // considering all subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_in_subarray;

            // Collect all unique elements in the current subarray
            for (int j = i; j < i + k; j++) {
                unique_in_subarray.insert(nums[j]);
            }

            // Increment the subarray appearance count for these elements
            for (int num : unique_in_subarray) {
                mp[num]++;
            }
        }
        int maxi = INT_MIN;
        for (auto it : mp) {
            if (it.second == 1) {
                // ek hi occurance hai
                maxi = max(maxi, it.first);
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};