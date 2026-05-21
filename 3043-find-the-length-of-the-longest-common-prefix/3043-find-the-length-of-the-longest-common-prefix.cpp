class Solution {
public:
    // we will solve it using the concept of trie
    struct trieNode {
        trieNode* children[10]; // 0 idx denotes 0, 1->1 and so on
        bool endword;
    };
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 10; i++) {
            newNode->children[i] = NULL;
        }

        newNode->endword = false;

        return newNode;
    }

    void insert(trieNode* root, string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int ch_idx = ch - '0';
            if (crawler->children[ch_idx] == NULL) {
                // we have to create a new node
                crawler->children[ch_idx] = getNode();
            }
            crawler = crawler->children[ch_idx];
        }
        crawler->endword = true;
    }

    int check(trieNode* root1, string word) {
        // make two crawlers for both the trees
        trieNode* crawler = root1;

        int len = 0;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int ch_idx = ch - '0';
            if (crawler->children[ch_idx] != NULL) {
                // we have to create a new node
                len++;

                crawler = crawler->children[ch_idx];
            } else {
                break;
            }
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root1 = getNode();
        for (int i = 0; i < arr1.size(); i++) {
            string temp = to_string(arr1[i]);
            insert(root1, temp);
        }
        int ans = 0;
        for (int i = 0; i < arr2.size(); i++) {
            string temp = to_string(arr2[i]);
            ans = max(ans, check(root1, temp));
        }
        return ans;
    }
};