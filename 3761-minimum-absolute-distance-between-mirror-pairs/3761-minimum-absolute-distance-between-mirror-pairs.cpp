class Solution {
public:
    int reverseNum(int x) {
        long long y = 0; // Use long long to handle potential overflow
        while (x > 0) {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        return (int)y;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, int> mp; // Map to store {value : last_seen_index}

        for (int i = 0; i < n; i++) {
            // If the current number matches a previously stored reversed value
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }
            
            // Store the reverse of the current number as the key
            // This waits for its match to appear later in the array
            mp[reverseNum(nums[i])] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
