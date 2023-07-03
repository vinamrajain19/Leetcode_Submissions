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
    
    TreeNode *f,*s,*prev;
    void inorder(TreeNode * root){
        if(!root) return;
        
        inorder(root->left);
        
        if(f == NULL and root->val < prev->val){
            f = prev;
        }
        
        if(f != NULL and root->val < prev->val){
            s = root;
        }
        
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(f->val,s->val);
    }
};