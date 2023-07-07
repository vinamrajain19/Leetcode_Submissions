/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     TreeNode * f(TreeNode * root,TreeNode * p,TreeNode *q){
        if(root == NULL) return NULL;
        
        if(p->val == root -> val or q->val == root->val){
            return root;
        }
        
        TreeNode * l = f(root->left,p,q);
        TreeNode * r = f(root->right,p,q);
        
        if(l == NULL and r == NULL) return NULL;
        else if(l != NULL and r == NULL) return l;
        else if(l == NULL and  r != NULL) return r;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     return f(root,p,q);   
    }
};