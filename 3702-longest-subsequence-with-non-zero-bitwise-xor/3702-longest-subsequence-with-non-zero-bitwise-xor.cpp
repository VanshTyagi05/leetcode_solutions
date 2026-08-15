class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int zeros=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zeros++;
            temp=temp^nums[i];
        }
        if(temp>0)return n;
        if(zeros==n)return 0;
        if(temp==0 & zeros<n)return n-1;
        return 0;
    }
};