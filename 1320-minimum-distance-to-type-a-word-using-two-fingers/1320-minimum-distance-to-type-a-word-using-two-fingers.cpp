class Solution {
public:
    int dp[301][26][26];

    int getdist(int f1, int f2) {
        int x1 = f1 / 6;
        int y1 = f1 % 6;
        int x2 = f2 / 6;
        int y2 = f2 % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int solve(string word, int i, int f1, int f2) {
        if (i >= word.size()) {
            return 0;
        }
        if (f1<26 && f2<26 && dp[i][f1][f2] != -1)
            return dp[i][f1][f2];
        char ch = word[i];
        int pos = ch - 'A';
        // if non of the finger is used erlier we can use any finger
        if (f1 == 26 && f2 == 26) {
            // use finger 1 means finger1 will now moe to x and y
            return solve(word, i + 1, pos, f2);
        }
        // if f2 is not used already
        if (f2 == 26) {
            // use it and dont use f1 as its already used
            int movef2 = 0 + solve(word, i + 1, f1, pos);
            int moveF1 = getdist(f1, pos) + solve(word, i + 1, pos, f2);
            return min(movef2, moveF1);
        }

        // both areused already
        int move1 = getdist(f1, pos) + solve(word, i + 1, pos, f2);
        int move2 = getdist(f2, pos) + solve(word, i + 1, f1, pos);

        return dp[i][f1][f2] = min(move1, move2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0,26,26);
    }
};