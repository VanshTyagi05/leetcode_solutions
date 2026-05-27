class Solution {
public:
    int n;
    int t[1001];
    int recur(int idx, vector<int>& nums, int target) {
        if (idx == n - 1) {
            return 0; // now dont need any steps
        }
        if(t[idx]!=-1)return t[idx];
        int curr_steps = INT_MIN;
        
        for (int i = idx + 1; i < n; i++) {
            if (abs(nums[i] - nums[idx]) <= target) {
                int next_steps = recur(i, nums, target);
                if (next_steps != INT_MIN) {
                    curr_steps = max(curr_steps, 1 + next_steps);
                }
            }
        }

        return t[idx]=curr_steps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        int ans = recur(0, nums, target);
        if (ans == INT_MIN)
            return -1;
        return ans;
    }
};