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
    
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        stack<TreeNode *> s;
        int prev = -1;
        int mn = 1e9;
        while(true){
            if(root != NULL){
                s.push(root);
               // prev = root->val;
                root = root->left;
            }
            else{
                if(s.size() == 0) break;
                root = s.top();
                s.pop();
                if(prev != -1){
                   mn = min(mn,root->val - prev);
                }
                prev = root->val;
                
                root = root->right;
            }
        
        }
        return mn;
    }
};