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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        stack<TreeNode * > s;
        s.push(root);
        while(s.size()!=0){
            TreeNode * t = s.top();
            s.pop();
            ans.push_back(t->val);
            
            if(t->left) s.push(t->left);
            if(t->right) s.push(t->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};