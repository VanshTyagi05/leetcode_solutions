class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long getLCM(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // mid tak kitne valid amounts hain
    long long countValid(long long mid, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // Saare subsets check karenge
        // Example coins = [2,3,5]
        // subsets:
        // {2}, {3}, {5}
        // {2,3}, {2,5}, {3,5}
        // {2,3,5}

        for (int mask = 1; mask < (1 << n); mask++) {

            long long lcm = 1;
            int bits = 0;
            bool tooBig = false;

            for (int i = 0; i < n; i++) {

                // Check karo ki ith coin subset mein hai ya nahi
                if (mask & (1 << i)) {

                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);

                    // Overflow avoid karne ke liye
                    if (lcm > mid / (coins[i] / g)) {
                        tooBig = true;
                        break;
                    }

                    lcm = (lcm / g) * coins[i];
                }
            }

            // Agar LCM > mid hai,
            // to mid/lcm = 0 hoga
            if (tooBig || lcm > mid)
                continue;

            long long cnt = mid / lcm;

            // Odd number of elements:
            // add karna hai
            if (bits % 2 == 1)
                ans += cnt;

            // Even number of elements:
            // subtract karna hai
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        // Binary Search
        while (low < high) {

            long long mid = low + (high - low) / 2;

            // Agar mid tak k ya usse zyada valid amounts hain
            if (countValid(mid, coins) >= k) {
                // Answer mid ya usse chhota ho sakta hai
                high = mid;
            }
            else {
                // k-th amount abhi aage hai
                low = mid + 1;
            }
        }

        return low;
    }
};