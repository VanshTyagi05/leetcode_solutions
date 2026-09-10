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
   int ans; // to store the count of nodes where the val=avg of its subtree
    pair<int,int> recur(TreeNode* root){
         if (root == NULL) {
            return {0, 0};
        }
        // pair-> {no_of_nodes,sum_of_subtree}

        pair<int,int> left=recur(root->left);
        pair<int,int> right=recur(root->right);
        int total_subtree_nodes=left.first+right.first+1;
        int sum=left.second+right.second+root->val;
        if(root->val==(sum/total_subtree_nodes)){
            ans++;
        }
        return {total_subtree_nodes,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        recur(root);
        return ans;
    }
};