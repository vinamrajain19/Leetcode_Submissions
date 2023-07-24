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
    
    int ans = 0;
    int h(TreeNode * root){
        if(!root) return 0;
        
        int l = h(root->left);
        int r= h(root->right);
        
        return 1 + max(l,r);
    }
    
    void f(TreeNode * root,int d,int &mx){
        if(!root) return;
        
        if(d == mx){
            ans += root->val;
        }
        
        f(root->left,d+1,mx);
        f(root->right,d+1,mx);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int d = h(root);
        f(root,1,d);
        return ans;
    }
};