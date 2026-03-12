#include <vector>
#include <vector>

class Solution {
public:
    int countTriplets(std::vector<int>& nums) {
        // The numbers are guaranteed to be less than 2^16
        const int MAX_VAL = 1 << 16;
        std::vector<int> pair_counts(MAX_VAL, 0);

        // Step 1: Pre-calculate the bitwise AND of all pairs (i, j)
        // This is O(N^2), which is 1000^2 = 1,000,000 operations
        for (int a : nums) {
            for (int b : nums) {
                pair_counts[a & b]++;
            }
        }

        int total_triplets = 0;

        // Step 2: Iterate through the original array for the third number k
        // For each num, check all possible results from pair_counts
        // This is O(N * 2^16), which is 1000 * 65,536 ≈ 65 million operations
        for (int k_val : nums) {
            for (int pair_and = 0; pair_and < MAX_VAL; ++pair_and) {
                // If there were any pairs that resulted in 'pair_and' 
                // and the final AND with k_val is 0, add them to the total
                if (pair_counts[pair_and] > 0 && (pair_and & k_val) == 0) {
                    total_triplets += pair_counts[pair_and];
                }
            }
        }

        return total_triplets;
    }
};
