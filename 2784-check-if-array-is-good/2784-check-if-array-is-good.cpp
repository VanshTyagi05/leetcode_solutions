class Solution {
public:
    bool isGood(vector<int>& nums) {
        int size = nums.size();
        if(size<2)return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                // we are at the last element
                if (nums[i] != nums[i - 1]) {
                    return false;
                }
            } else {
                if (i + 1 != nums[i])
                    return false;
            }
        }
        return true;
    }
};