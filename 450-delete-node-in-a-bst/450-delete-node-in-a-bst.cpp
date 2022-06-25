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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
             return NULL;
        }   
        
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key> root->val){
            root->right= deleteNode(root->right,key);
        }
        else{
            if(!root->left and !root->right){
                return NULL;
            }
            else if(root-> left and !root->right){
                return root->left;
            }
            else if(!root->left and root->right){
                return root->right;
            } 
            else{
                TreeNode * temp = root->right;
                
                while(temp->left != NULL) temp = temp -> left;
                root->val = temp -> val;
                
                root -> right = deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};