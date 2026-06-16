class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
           auto it=lower_bound(begin(sorted),end(sorted),nums[i]);
           ans.push_back(it - sorted.begin());
           sorted.insert(it,nums[i]);
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};