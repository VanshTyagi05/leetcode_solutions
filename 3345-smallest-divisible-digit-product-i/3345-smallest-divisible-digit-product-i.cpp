class Solution {
public:
    int findProduct(int n) {
        int ans = 1;
        while (n > 0) { // Fix: Must check n > 0 to include the last digit
            ans *= (n % 10);
            n /= 10;
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        // Linearly increment until the condition is met
        while (true) {
            if (findProduct(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};
