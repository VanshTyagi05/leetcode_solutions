class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long total_x = 0;
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            // If there is a dip from the previous element to the current element
            if (nums[i - 1] > nums[i]) {
                total_x += (nums[i - 1] - nums[i]);
            }
        }
        
        return total_x;
    }
};
