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
    
    void f(TreeNode * root,int &ans,int cnt,int dir){
        if(root==NULL) return;
        
        ans = max(ans,cnt);
        
        if(dir == 1){
            f(root->right,ans,cnt+1,2);
            f(root->left,ans,1,1);
        }
        else{
            f(root->left,ans,cnt+1,1);
            f(root->right,ans,1,2);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        f(root,ans,0,1);
        f(root,ans,0,2);
        return ans;
    }
};