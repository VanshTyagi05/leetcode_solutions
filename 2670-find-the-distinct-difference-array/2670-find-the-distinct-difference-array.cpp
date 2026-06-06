class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);

            leftSum[i] = s.size();
        }
        set<int>s2;
        for (int i = n - 1; i >= 0; i--) {
            s2.insert(nums[i]);
            rightSum[i] = s2.size();
            
        }

        vector<int>ans(n);
        for(int i=0;i<n-1;i++){
            ans[i]=(leftSum[i]-rightSum[i+1]);
        }
        ans[n-1]=leftSum[n-1];
        return ans;
    }
};