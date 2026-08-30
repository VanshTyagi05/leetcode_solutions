class Solution {
    public int minimumDeletions(int[] nums) {
        int n=nums.length;
        int min_idx=0;
        int max_idx=0;
        for(int i=0;i<n;i++){
           if(nums[i]>nums[max_idx]){
            max_idx=i;
           }
           if(nums[i]<nums[min_idx]){
            min_idx=i;
           }
        } 

        // Identify the smaller and larger index to simplify calculations
        int left = Math.min(min_idx, max_idx);
        int right = Math.max(min_idx, max_idx);
        
        // Case 1: Remove both from the front (up to the right-most element)
        int case1 = right + 1; 
        
        // Case 2: Remove both from the back (up to the left-most element)
        int case2 = n - left; 
        
        // Case 3: Remove the left one from the front, and the right one from the back
        int case3 = (left + 1) + (n - right); 
        
        // Return the minimum of the three choices
        return Math.min(case1, Math.min(case2, case3));
    }
}