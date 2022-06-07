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
    void rec(TreeNode * root,int s,vector<vector<int>> &ans,vector<int> &path){
        if(root == NULL) return;
        
        path.push_back(root->val);
        
        if(root->left == NULL and root->right == NULL and s == root->val){
            ans.push_back(path);
        }
        
        rec(root->left,s-root->val,ans,path);
        rec(root->right,s-root->val,ans,path);
        
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        rec(root,targetSum,ans,path);
        return ans;
        
    }
};