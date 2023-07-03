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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        
        while(q.size()){
            int n = q.size();
            vector<int> res;
            while(n--){
                TreeNode * t = q.front();
                q.pop();
                
                res.push_back(t->val);
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};