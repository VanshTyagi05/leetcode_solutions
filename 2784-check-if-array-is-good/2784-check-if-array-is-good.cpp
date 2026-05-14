class Solution {
public:
    bool isGood(vector<int>& nums) {
        int size = nums.size();
        // A valid base[n] array must have at least 2 elements (n=1 -> [1, 1])
        if (size < 2) return false; 
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                // The last element must mirror the second-to-last element
                if (nums[i] != nums[i - 1]) {
                    return false;
                }
            } else {
                // Elements before the last one must strictly match 1, 2, 3...
                if (i + 1 != nums[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
