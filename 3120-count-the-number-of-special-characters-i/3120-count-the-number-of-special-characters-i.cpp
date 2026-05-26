class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26);
        vector<int> upper(26);
        int ans = 0;
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a']++;
            } else {
                upper[ch - 'A']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lower[i] > 0 && upper[i] > 0) {
                ans++;
            }
        }
        return ans;
    }
};