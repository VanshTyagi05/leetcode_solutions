class Solution {
    // memo[i][canChange] stores the maximum index 'j' in word2 we reached from this state.
    // If we visit this state again with a lower or equal 'j', it means this path is suboptimal.
    vector<vector<int>> memo;
    vector<int> result;
    bool found = false;

    bool solve(int i, int j, int canChange, string& word1, string& word2, vector<int>& current_path) {
        // Base Case 1: Successfully matched all characters of word2
        if (j == word2.size()) {
            result = current_path;
            found = true;
            return true;
        }
        // Base Case 2: Ran out of characters in word1
        if (i == word1.size()) {
            return false;
        }

        // Memoization check: If we've seen this (i, canChange) state before with a better or equal j, skip it
        if (memo[i][canChange] >= j) {
            return false;
        }
        memo[i][canChange] = j;

        // Branch 1: Try to INCLUDE word1[i] (Greedy choice for lexicographically smallest index)
        // Case A: Natural Match
        if (word1[i] == word2[j]) {
            current_path.push_back(i);
            if (solve(i + 1, j + 1, canChange, word1, word2, current_path)) {
                return true;
            }
            current_path.pop_back(); // Backtrack
        } 
        // Case B: Mismatch, but we have a modification token left
        else if (canChange == 1) {
            current_path.push_back(i);
            if (solve(i + 1, j + 1, 0, word1, word2, current_path)) {
                return true;
            }
            current_path.pop_back(); // Backtrack
        }

        // Branch 2: Try SKIPPING word1[i] to pick a later index instead
        if (solve(i + 1, j, canChange, word1, word2, current_path)) {
            return true;
        }

        return false;
    }

public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        
        // Initialize memoization table: size [n][2] initialized to -1
        memo.assign(n, vector<int>(2, -1));
        
        vector<int> current_path;
        solve(0, 0, 1, word1, word2, current_path);
        
        return result;
    }
};
