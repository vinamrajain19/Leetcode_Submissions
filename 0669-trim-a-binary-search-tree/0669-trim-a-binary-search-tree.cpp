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

    
    
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return root;
        
        // root < l -> means all val left of root will also be less than then we can return root -> right
        if(root->val < low){
            return trimBST(root->right,low,high);
        }
        //same for root -> right
        if(root->val > high){
            return trimBST(root->left,low,high);
        }
        
        //root ->val lies in range call for both left and right
        root -> left = trimBST(root->left,low,high);
        root -> right = trimBST(root->right,low,high);
        
        return root;
    }
};