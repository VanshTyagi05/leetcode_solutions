

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        // Step 1: Concatenate all chunks together sequentially
        string s = "";
        for (const string& chunk : chunks) {
            s += chunk;
        }

        unordered_map<string, int> word_freq;
        string current_word = "";
        int n = s.length();

        // Step 2: Iterate through the combined string to extract valid words
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                // Regular lowercase letter is always part of the word
                current_word += ch;
            } else if (ch == '-' && i > 0 && i < n - 1 &&
                       (s[i - 1] >= 'a' && s[i - 1] <= 'z') &&
                       (s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                // Valid joiner hyphen (surrounded by lowercase letters)
                current_word += ch;
            } else {
                // Hit a separator character! Save the accumulated word if it
                // exists
                if (!current_word.empty()) {
                    word_freq[current_word]++;
                    current_word = ""; // Reset for the next word
                }
            }
        }

        // Edge Case: Don't forget to push the very last word if the string
        // didn't end with a separator
        if (!current_word.empty()) {
            word_freq[current_word]++;
        }

        // Step 3: Map results to answers while avoiding
        // out-of-bounds/segmentation faults
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = word_freq[queries[i]]; // Evaluates automatically to 0 if
                                            // missing
        }

        return ans;
    }
};
