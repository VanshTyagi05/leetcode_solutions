class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        // Use double to ensure ceil works correctly
        int numgrp = ceil((double)n / k);
        int i = 0;

        while (numgrp > 0) {
            string temp = "";
            int j = i;
            int target = i + k;
            while (j < target) {
                // FIX 1: Only add characters if we are within the string bounds
                if (j < n) {
                    temp += s[j];
                }
                j++;
            }
            i = j; // Move i to the next group start
            ans.push_back(temp);
            numgrp--;
        }

        // FIX 2: Check the last element's actual size dynamically
        while (ans.back().size() < k) {
            ans.back() += fill;
        }

        return ans;
    }
};
