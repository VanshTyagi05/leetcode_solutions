class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childrenSet; // Bacho ka track rakhne ke liye

        for (const auto& d : descriptions) {
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2];

            // 1. Agar parent map mai nahi hai, toh naya banao
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            // 2. Agar child map mai nahi hai, toh naya banao
            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            // 3. Pointers ko connect karo
            if (isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            // 4. Child ko set mai daal do
            childrenSet.insert(child);
        }

        // 5. Root dhoondo: Aisa parent jo kisi ka child nahi hai
        for (const auto& d : descriptions) {
            int parent = d[0];
            if (childrenSet.find(parent) == childrenSet.end()) {
                return mp[parent]; // Yeh hi hamara main root hai
            }
        }

        return nullptr;
    }
};
