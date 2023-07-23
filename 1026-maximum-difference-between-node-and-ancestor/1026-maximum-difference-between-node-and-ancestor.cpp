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
    
    // max(a.val - b.val) will be diff b/w max and min val of a particular subtree

    int ans = -1e9;

    void f(TreeNode * root,int mx,int mn){
        if(root == NULL){
           ans = max(ans,mx-mn);
           return;
        }

        mx = max(root->val,mx);
        mn = min(root->val,mn);

        f(root->left,mx,mn);
        f(root->right,mx,mn);
    }

    int maxAncestorDiff(TreeNode* root) { 
        int mn = INT_MAX;
        int mx = INT_MIN;

        f(root,mx,mn);
        return ans;
    }
};