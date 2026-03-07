class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        // At the start, the sequence of 1 element can be considered 
        // both an 'up' and a 'down' ending sequence.
        int up = 1; 
        int down = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // A rise can only extend a sequence that previously ended in a fall
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                // A fall can only extend a sequence that previously ended in a rise
                down = up + 1;
            }
            // Note: if nums[i] == nums[i-1], up and down remain unchanged
        }

        // The answer is the maximum of the two possible ending states
        return max(up, down);
    }
};
