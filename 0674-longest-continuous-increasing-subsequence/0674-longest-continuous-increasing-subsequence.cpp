class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int i=1;
        int count=1;
        int ans=1;
        while(i<n){
            if(nums[i-1]<nums[i]){
                count++;
                ans=max(ans,count);
            }else{
                count=1;
            }
            i++;
        }

        return ans;
    }
};