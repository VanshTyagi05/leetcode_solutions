class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int counts=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    counts++;
                }

                if(counts>(j-i+1)/2){
                    ans++;
                }
            }
        }

        return ans;
    }
};