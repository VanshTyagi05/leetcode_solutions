class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n=nums.length;
        int[] left = new int[n];
        int[] right=new int[n];
        int maxi=nums[0];
        int mini=nums[n-1];
        // going from left to right
        for(int i=0;i<n;i++){
            maxi=Math.max(maxi,nums[i]);
            left[i]=maxi;
        }
        for(int i=n-1;i>=0;i--){
            mini=Math.min(mini,nums[i]);
            right[i]=mini;
        }

        for(int i=0;i<n;i++){
            if(left[i]-right[i]<=k){
                return i;
            }
        }
        return -1;
    }
}