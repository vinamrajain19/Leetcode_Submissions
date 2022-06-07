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
    bool c(TreeNode* root, int Sum){
        if(root == NULL) return false;
        
        if(root->val == Sum and root->left == NULL and root->right == NULL) return true;
        
        return c(root->left,Sum - root->val) or c(root->right,Sum - root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return c(root,targetSum);
        
    }
};