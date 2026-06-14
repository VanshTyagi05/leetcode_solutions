class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        vector<int>dp(n,0);
        int ans=0;
        // dp[i]= number of arithmetic subarrays ending at i
        // dp[0]=dp[1]=0; // not possible for lenght of 2 minimum lenght is 3
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                // ye ban gya arithmetic slice ab dekho dp[i-1] tak kitna anser tha usme +1 krdo
                dp[i]=dp[i-1]+1;
            }
            ans+=dp[i];
        }

        return ans;
    }
};