class Solution {
public:
    int n;
    bool ispredecessor(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (n2 - n1 != 1)
            return false;
        int i = 0; // iterator on first
        int j = 0; // iteratror on second
        int diff = 0;
        while (i < n1 && j < n2) {
            if (word1[i] == word2[j]) {
                i++;
                
            } 
            j++;
        }

        return i==word1.size();
    }
    int dp[1001][1002];
    int solve(int idx, vector<string>& words, int prev) {
        if (idx >= n) {
            return 0;
        }
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];

        int take = 0;
        if (prev == -1 || ispredecessor(words[prev], words[idx])) {
            take = 1 + solve(idx + 1, words, idx);
        }

        int not_take = solve(idx + 1, words, prev);

        return dp[idx][prev+1]=max(take, not_take);
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end(),
             [](string a, string b) { return a.size() < b.size(); });
        memset(dp,-1,sizeof(dp));
        return solve(0, words, -1);
    }
};
