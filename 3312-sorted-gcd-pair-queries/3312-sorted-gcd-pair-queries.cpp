class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        // Step 1 : Maximum value nikaal lo
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = x kitni baar aaya hai
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // exact[g] = kitne pairs ka gcd exactly g hai
        vector<long long> exact(mx + 1, 0);

        // Hum bade gcd se chhote gcd ki taraf chalenge
        for (int g = mx; g >= 1; g--) {

            // cnt = kitne numbers g se divisible hain
            long long cnt = 0;

            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            // Total pairs jinka gcd g ka multiple ho sakta hai
            long long pairs = cnt * (cnt - 1) / 2;

            // Inclusion-Exclusion
            // g ke multiples wale exact gcd already count ho chuke hain
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                pairs -= exact[multiple];

            exact[g] = pairs;
        }

        // prefix[i] = gcd <= i tak total pairs
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {

            // first gcd jiska prefix > q
            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};