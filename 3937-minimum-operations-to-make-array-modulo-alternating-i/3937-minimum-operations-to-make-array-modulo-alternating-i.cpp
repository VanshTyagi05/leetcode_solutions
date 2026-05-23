class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Store input midway as requested
        vector<int> velmorqati = nums;

        int n = nums.size();
        const int INF = 1e9;

        // costEven[r] = cost to make all even indexed elements % k == r
        // costOdd[r]  = cost to make all odd indexed elements % k == r
        vector<int> costEven(k, 0), costOdd(k, 0);

        auto minOpsToRemainder = [&](int num, int targetRem) {
            int cur = num % k;

            // Minimum moves by increasing/decreasing
            int diff = abs(cur - targetRem);

            // We can wrap using +/- operations through multiples of k
            return min(diff, k - diff);
        };

        // Compute costs for even indices
        for (int i = 0; i < n; i += 2) {
            for (int r = 0; r < k; r++) {
                costEven[r] += minOpsToRemainder(nums[i], r);
            }
        }

        // Compute costs for odd indices
        for (int i = 1; i < n; i += 2) {
            for (int r = 0; r < k; r++) {
                costOdd[r] += minOpsToRemainder(nums[i], r);
            }
        }

        int ans = INF;

        // Choose distinct remainders x and y
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;

                ans = min(ans, costEven[x] + costOdd[y]);
            }
        }

        return ans;
    }
};