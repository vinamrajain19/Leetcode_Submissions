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
    int f(TreeNode * root){
        if(!root) return 0;
        
        int l = f(root->left);
        int r = f(root->right);
        
        return 1 + max(l,r);
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};