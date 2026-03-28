class Solution {
public:
    string getLine(int i, int j, int eachWordSpace, int extraSpace, vector<string>& words, int maxWidth) {
        string s;
        for (int k = i; k < j; k++) {
            s += words[k];
            if (k == j - 1) break; // Don't add spaces after the last word of the line

            for (int space = 0; space < eachWordSpace; space++) s += " ";
            
            if (extraSpace > 0) {
                s += " ";
                extraSpace--;
            }
        }
        // Pad the right side if the line is shorter than maxWidth (handles last line & single words)
        while (s.length() < maxWidth) s += " ";
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0, n = words.size();
        
        while (i < n) {
            int j = i + 1;
            int lineLetters = words[i].length();
            
            // Determine how many words fit in this line
            while (j < n && lineLetters + words[j].length() + (j - i) <= maxWidth) {
                lineLetters += words[j].length();
                j++;
            }

            int spaceSlots = j - i - 1;
            int eachWordSpace = 0;
            int extraSpace = 0;

            // If it's not the last line and there's more than one word
            if (j < n && spaceSlots > 0) {
                eachWordSpace = (maxWidth - lineLetters) / spaceSlots;
                extraSpace = (maxWidth - lineLetters) % spaceSlots;
            } else {
                // Last line or single-word line: left justified
                eachWordSpace = 1;
                extraSpace = 0;
            }

            ans.push_back(getLine(i, j, eachWordSpace, extraSpace, words, maxWidth));
            i = j;
        }
        return ans;
    }
};
