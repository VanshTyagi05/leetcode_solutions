class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    int n = s.size(), numWords = words.size(), wordLen = words[0].size();
    if (n < numWords * wordLen)
        return ans;

    unordered_map<string, int> counts;
    for (const string& w : words)
        counts[w]++;

    // Run the window for each possible starting offset (0 to wordLen-1)
    for (int i = 0; i < wordLen; i++) {
        int left = i, count = 0;
        unordered_map<string, int> seen;

        for (int j = i; j <= n - wordLen; j += wordLen) {
            string word = s.substr(j, wordLen);
            if (counts.count(word)) {
                seen[word]++;
                count++;

                // If we have too many of 'word', slide the left pointer
                while (seen[word] > counts[word]) {
                    seen[s.substr(left, wordLen)]--;
                    count--;
                    left += wordLen;
                }

                // Success!
                if (count == numWords)
                    ans.push_back(left);
            } else {
                // Not a valid word, reset the window
                seen.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    return ans;
}
};
