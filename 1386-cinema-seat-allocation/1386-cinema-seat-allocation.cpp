#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map to store row -> bitmask of reserved seats
        unordered_map<int, int> reservedRows;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Set the bit corresponding to the column (1-indexed)
            reservedRows[row] |= (1 << col);
        }
        
        // Start by assuming all rows can fit 2 families max
        int maxFamilies = n * 2;
        
        // Now deduct families only for rows that have reservations
        for (auto const& [row, mask] : reservedRows) {
            bool leftValid = true;
            bool rightValid = true;
            bool middleValid = true;
            
            // Check Left Block: columns 2, 3, 4, 5
            for (int c = 2; c <= 5; c++) {
                if (mask & (1 << c)) leftValid = false;
            }
            
            // Check Right Block: columns 6, 7, 8, 9
            for (int c = 6; c <= 9; c++) {
                if (mask & (1 << c)) rightValid = false;
            }
            
            // Check Middle Block: columns 4, 5, 6, 7
            for (int c = 4; c <= 7; c++) {
                if (mask & (1 << c)) middleValid = false;
            }
            
            // Deduct from the initial maximum of 2 families for this row
            if (leftValid && rightValid) {
                // Both fit, no deduction needed
                continue;
            } else if (leftValid || rightValid || middleValid) {
                // Only 1 family can fit instead of 2
                maxFamilies -= 1;
            } else {
                // No families can fit instead of 2
                maxFamilies -= 2;
            }
        }
        
        return maxFamilies;
    }
};
