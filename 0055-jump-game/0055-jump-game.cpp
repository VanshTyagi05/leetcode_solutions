class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_reachable = max(max_reachable, i + nums[i]);
            if (max_reachable >= n - 1)
                return true;
            if (i == n - 2 && max_reachable <= n - 1) {
                return false;
            }
            if(i==max_reachable && nums[i]==0)return false;
            
        }

        return true;
    }
};