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
     int ans = 0;
     void f(TreeNode * root,string t){
         if(root == NULL) return;
         
         if(root->left == NULL and root->right == NULL){
             t.push_back(root->val + '0');
             ans += stoi(t);
             cout<<ans<<endl;
             return;
         }
        

        f(root->left,t+to_string(root->val));
        f(root->right,t+to_string(root->val)); 
     
    }
    
    
    int sumNumbers(TreeNode* root) {
        f(root,"");
        return ans;
    }
};