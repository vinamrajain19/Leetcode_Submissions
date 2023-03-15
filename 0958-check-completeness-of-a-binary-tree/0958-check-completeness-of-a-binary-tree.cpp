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
    
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        
        int f = 1;
        while(q.size()){
            TreeNode * t = q.front();
            q.pop();
            
            if(t == NULL) f = 0;
            else{
                if(f == 0) return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};