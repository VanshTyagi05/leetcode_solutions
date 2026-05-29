class Solution {
public:
    // Returns pair: {max_money_if_rob_root, max_money_if_skip_root}
    pair<int, int> helper(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        auto left = helper(root->left);
        auto right = helper(root->right);

        // If we rob this node, we CANNOT rob its children
        int rob_this = root->val + left.second + right.second;

        // If we skip this node, children can either be robbed or skipped (take max of each)
        int skip_this = max(left.first, left.second) + max(right.first, right.second);

        return {rob_this, skip_this};
    }

    int rob(TreeNode* root) {
        auto result = helper(root);
        return max(result.first, result.second);
    }
};
