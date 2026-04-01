class Solution {
public:
    vector<string> ans;

    struct trieNode {
        trieNode* children[26];
        bool endWord;
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->endWord = false;
        return newNode;
    }

    void insert(trieNode*& root, string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (crawler->children[ch - 'a'] != NULL) {
                crawler = crawler->children[ch - 'a'];
            } else {
                crawler->children[ch - 'a'] = getNode();
                crawler = crawler->children[ch - 'a'];
            }
        }
        crawler->endWord = true;
    }
    unordered_map<int, vector<string>> dp;
    vector<string> search(trieNode* root, int idx, string& word) {
        if (dp.count(idx))
            return dp[idx];

        vector<string> result;
        if (idx == word.size()) {
            result.push_back("");
            return result;
        }

        trieNode* crawler = root;
        string temp = "";

        // FIX: Use a separate loop variable 'i' so 'idx' remains untouched
        for (int i = idx; i < word.size(); i++) {
            int ch_idx = word[i] - 'a';
            if (crawler->children[ch_idx] == NULL)
                break; // No further words possible in this branch

            crawler = crawler->children[ch_idx];
            temp += word[i]; // simpler way to add the character

            if (crawler->endWord) {
                // FIX: Recurse starting exactly from the NEXT character (i + 1)
                vector<string> subResults = search(root, i + 1, word);
                for (const string& sub : subResults) {
                    if (sub.empty()) {
                        result.push_back(temp);
                    } else {
                        result.push_back(temp + " " + sub);
                    }
                }
            }
        }

        return dp[idx] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trieNode* root = getNode();
        for (int i = 0; i < wordDict.size(); i++) {
            insert(root, wordDict[i]);
        }
        return search(root, 0, s);
    }
};