class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        // Frequency count
        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special handling for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        // Try every unique number as starting point
        for (auto &[num, cnt] : freq) {

            if (num == 1)
                continue;

            long long curr = num;
            int levels = 0;

            while (freq.count(curr) && freq[curr] >= 2) {

                levels++;

                // Prevent overflow
                if (curr > 1000000000LL / curr)
                    break;

                curr = curr * curr;
            }

            // Current number can be the center
            if (freq.count(curr) && freq[curr] == 1)
                ans = max(ans, 2 * levels + 1);

            // Otherwise go one level back
            else
                ans = max(ans, 2 * levels - 1);
        }

        return ans;
    }
};