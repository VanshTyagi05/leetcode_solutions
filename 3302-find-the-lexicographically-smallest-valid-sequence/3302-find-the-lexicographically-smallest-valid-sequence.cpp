class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> matched_from_right_side(n, 0);
        int matched = 0;
        int i = n - 1;
        int j = m - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                matched++;
                j--;
            }
            matched_from_right_side[i] = matched;
            i--;
        }
        // If there are remaining elements after j exits, fill the rest of the
        // suffix array
        while (i >= 0) {
            matched_from_right_side[i] = matched;
            i--;
        }
        i = 0;
        j = 0; // restarting from the start to start matching
        vector<int> ans;
        bool canChange = true;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
                continue;
            } else {
                int remaining_matches =
                    (i + 1 < n) ? matched_from_right_side[i + 1] : 0;
                if (canChange == true && remaining_matches >= m - j - 1) {
                    canChange = false;
                    ans.push_back(i);
                    i++;
                    j++;
                    continue;
                } else {
                    // agr aise change na kr pao toh bas i ko aage badha do
                    i++;
                }
            }
        }
        if (ans.size() < m) return {};
        return ans;
    }
};