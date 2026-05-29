class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            int curr=nums[i];
            while(curr>0){
                sum+=curr%10;
                curr/=10;
            }
            mini=min(sum,mini);
        }

        return mini;
    }
};