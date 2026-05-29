/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     unordered_map<TreeNode* ,vector<int>>dp;
    int solve(TreeNode* root,bool parent_robbed){
        if(root==NULL)return 0;
        int case1=0;
        // Check if this exact state (node + parent condition) is already memoized
        if (dp.count(root) && dp[root][parent_robbed] != -1) {
            return dp[root][parent_robbed];
        }

        // Initialize memoization entry for this node if it doesn't exist
        if (!dp.count(root)) {
            dp[root] = {-1, -1};
        }
        if(parent_robbed==false){
          case1=root->val+solve(root->left,true)+solve(root->right,true);
        }

        int case2; // here the parent is robbed and you can rob the current and must leave it
        case2=solve(root->left,false)+solve(root->right,false);

        return dp[root][parent_robbed]= max(case1,case2);

    }
    int rob(TreeNode* root) {
        dp.clear();
        return solve(root,false);
    }
};