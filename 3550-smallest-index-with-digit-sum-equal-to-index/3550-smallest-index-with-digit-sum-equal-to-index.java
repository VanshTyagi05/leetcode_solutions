class Solution {
    public int sum(int n){
        int ans=0;
        while(n>0){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    public int smallestIndex(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(sum(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
}