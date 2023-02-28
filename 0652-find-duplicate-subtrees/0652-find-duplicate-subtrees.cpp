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
    unordered_map<string,int> m;
    vector<TreeNode *> ans;
    
    string f(TreeNode * root){
        if(root == nullptr) return "";
        
        string s = "(" + to_string(root->val) + "#" + f(root->left) + "#" + f(root->right) + ")";
        
        m[s]++;
        if(m[s] == 2) ans.push_back(root);
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        f(root);
        return ans;
    }
};