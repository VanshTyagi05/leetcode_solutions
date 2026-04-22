class Solution {
public:
    struct trieNode {
        trieNode* children[26];
        bool endword;
    };

    trieNode* createNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->endword = false;
        return newNode;
    }

    void addword(trieNode* root, string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (crawler->children[ch - 'a'] == NULL) {
                // mtlb ye added nhi hai toh isko add kro
                crawler->children[ch - 'a'] = createNode();
            }

            crawler = crawler->children[ch - 'a'];
        }
        crawler->endword = true;
    }

    bool canmatch(trieNode* root, string& target, int idx, int edits) {
        if (edits < 0)
            return false;
        if (idx == target.size())
            return true;

        int targetidx = target[idx] - 'a'; // hume ye charcater dhundna hai
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                // checlk kro kya targetidx ke barabr hai
                int nextEdits = (i == targetidx) ? edits : edits - 1;
                if (canmatch(root->children[i], target, idx + 1, nextEdits)) {
                    return true;
                }
            }
        }

        return false;
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

        trieNode* root = createNode();
        for (int i = 0; i < dictionary.size(); i++) {
            addword(root, dictionary[i]);
        }

        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (canmatch(root, queries[i], 0, 2)) {
                ans.push_back(queries[i]);
            }
        }
        return ans;
    }
};