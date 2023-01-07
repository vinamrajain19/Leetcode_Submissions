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
    bool f(TreeNode * root,long mn,long mx){
        if(root == NULL) return true;
        
        if(root->val <= mn or root->val >= mx) return false;
        
        return f(root->left,mn,root->val) and f(root->right,root->val,mx);
    }
    
    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN,LONG_MAX);
    }
};