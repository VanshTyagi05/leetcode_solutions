class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum-x;// find subarray of this target sun
        if(target==0)return n;
        if(target<0) return -1;

        int current_sum=0;
        int start=0;
        int max_length=-1;
        for(int end=0;end<n;end++){
            current_sum+=nums[end];
            while(current_sum>target && start<=end){
                current_sum-=nums[start];
                start++;
            }
            if(current_sum==target){
                max_length=Math.max(max_length,end-start+1);
            }
        }
        return max_length==-1?-1:n-max_length;
    }
}