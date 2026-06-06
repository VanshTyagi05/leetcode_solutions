class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftSum(n);
        vector<int>rightSum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            leftSum[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            rightSum[i]=sum;
            sum+=nums[i];
        }
        int ans=INT_MAX;
       for(int i=n-1;i>=0;i--){
           if(leftSum[i]==rightSum[i]){
            ans=min(ans,i);
           }
       }

       return ans==INT_MAX?-1:ans;
    }
};