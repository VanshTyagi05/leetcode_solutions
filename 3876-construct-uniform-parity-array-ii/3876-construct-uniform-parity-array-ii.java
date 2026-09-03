class Solution {
    public boolean uniformArray(int[] nums1) {
         // Use Integer.MAX_VALUE as the equivalent to C++ INT_MAX
        int minOdd = Integer.MAX_VALUE;
        boolean hasOdd = false;

        // Step 1: Find the minimum odd number
        for (int num : nums1) {
            if (num % 2 != 0) {
                hasOdd = true;
                minOdd = Math.min(minOdd, num);
            }
        }

        // Step 2: If no odd elements exist, return true
        if (!hasOdd) {
            return true;
        }

        // Step 3: Ensure no even element is smaller than the minimum odd element
        for (int num : nums1) {
            if (num % 2 == 0 && minOdd > num) {
                return false;
            }
        }

        return true;
    }
}