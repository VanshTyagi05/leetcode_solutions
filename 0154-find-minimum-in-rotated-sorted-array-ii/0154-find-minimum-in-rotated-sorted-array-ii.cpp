class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1])
                continue;
            else
                sum = nums[i];
        }
        return sum;
    }
};