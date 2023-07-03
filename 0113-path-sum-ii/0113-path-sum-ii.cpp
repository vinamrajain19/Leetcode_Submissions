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
    
    
    void f(TreeNode * root,int &tar,int sum,vector<int> &t,vector<vector<int>> &ans){
        if(!root) return;
        
        
        t.push_back(root->val);
        
        if(sum+root->val == tar and root->left == NULL and root->right == NULL){
            ans.push_back(t);
        }
        
        f(root->left,tar,sum+root->val,t,ans);
        f(root->right,tar,sum+root->val,t,ans);
        
        t.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> t;
        vector<vector<int>> ans;
        f(root,targetSum,0,t,ans);
        return ans;
    }
};